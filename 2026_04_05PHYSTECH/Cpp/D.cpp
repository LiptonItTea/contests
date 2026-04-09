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

struct Seg {
    ll l, r;
};

bool sort_backward(Seg &s1, Seg &s2) {
    return s1.l > s2.l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<Seg> backward;
    for (int i = 0; i < n; i++) {
        Seg s;
        cin >> s.l >> s.r;

        if (s.l < s.r) {

        }
        else
            backward.push_back(s);
    }

    sort(backward.begin(), backward.end(), sort_backward);

    vector<Seg> true_backward;
    Seg curr = backward[0];
    ll greedy_backward = 0;
    for (int i = 1; i < backward.size(); i++) {
        if (backward[i].l < curr.r) {
            true_backward.push_back(curr);
            curr = backward[i];
        }
        else
            curr.r = min(curr.r, backward[i].r);
    }
    true_backward.push_back(curr);

    ll result = m;
    for (int i = 0; i < true_backward.size(); i++) {
        result += 2 * (true_backward[i].l - true_backward[i].r);
    }

    cout << result;
}