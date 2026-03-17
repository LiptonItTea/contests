#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

vector<int> fact {1, 1, 2};
ll getFact(int n) {
    while (n >= fact.size()) {
        fact.push_back(*(fact.rbegin()) * fact.size());
    }
    return fact[n];
}

ll comb(int i, int k) {
    return getFact(k) / getFact(i) / getFact(k - i);
}

struct Entry {
    int ind, num;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll n, m, k;
    cin >> n >> m >> k;

    list<Entry> number;
    for (ll i = 0; i <= k; i++) {
        int ind = n * k + i * (m - n);
        int num = comb(i, k);

        auto it = number.begin();
        while (it != number.end() && it->ind < ind)
            it++;

        int j = 0; // delta
        while (num > 0) {
            int digit = num % 2;

            if (it == number.end() || ind + j < it->ind) {
                Entry e;
                e.ind = ind + j;
                e.num = digit;
                number.insert(it, e);
            }
            else {
                it->num += digit;
                it++;
            }

            j++;
            num /= 2;
        }
    }

    int saved = 0;
    int prev1 = -1;
    for (auto it = number.begin(); it != number.end(); it++) {
        while (prev1 + 1 < it->ind && saved > 0) {
            number.insert(it, {prev1 + 1, 1});
            prev1++;
            saved--;
        }

        it->num += saved;
        saved = 0;

        if (it->num > 1) {
            saved = it->num / 2;
            it->num %= 2;

            prev1 = it->ind;
        }
    }
    while (saved > 0) {
        number.insert(number.end(), {prev1 + 1, 1});
        prev1++;
        saved--;
    }

    int score = 0;
    for (auto it = number.begin(); it != number.end(); it++)
        if (it->num == 1)
            score++;

    cout << score;
}