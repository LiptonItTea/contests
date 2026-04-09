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

struct FenTree {
    vector<ll> a;
    int size;

    FenTree(int size) {
        this->size = size;
        a.assign(size, 0);
    }

    void add(ll i, ll v) {
        for (; i < size; i = i | (i + 1))
            a[i] += v;
    }

    ll sum(ll i) {
        ll result = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            result += a[i];

        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll n;
    cin >> n;

    vector<ll> c (n);
    map<ll, int> ctoi;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ctoi[c[i]] = i;
    }

    vector<ll> renumerate_c (n);
    for (int i = 0; i < n; i++) {
        renumerate_c[i] = c[i] + 1;
        if (renumerate_c[i] > n)
            renumerate_c[i] = 1;
    }

    FenTree ft (n);
    ll best_result = 0;
    for (ll i = 0; i < n; i++) {
        best_result += i - ft.sum(renumerate_c[i] - 1ll);
        ft.add(renumerate_c[i] - 1ll, 1);
    }

    ll curr_result = best_result;
    for (int i = n - 1; i >= 2; i--) {
        ll index = ctoi[i];

        ll result = curr_result + 2ll * index - n + 1ll;
        curr_result = result;
        best_result = min(best_result, curr_result);
    }

    cout << best_result;
}