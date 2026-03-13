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

ll f(ll c, ll k) {
    ll total = 0;
    if (c <= k)
        total = (1ll + c) * c / 2ll;
    else {
        total = (1ll + k) * k / 2ll;
        
        total += (3 * k - c - 1) * (c - k) / 2;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        ll k, x;
        cin >> k >> x;

        ll l = 1;
        ll r = 2 * k;

        while (r - l > 2) {
            int c = (l + r) / 2;

            ll total = f(c, k);

            // cout << l << " " << r << " " << c << " " << total << " " << (total > x ? ">" : "<=") << "\n";

            if (total == x)
                break;
            if (total > x)
                r = c + 1;
            else
                l = c;
        }

        ll best = -1;

        if (f(l, k) <= x - 1 || l > 1 && f(l - 1, k) <= x - 1)
            best = max(best, l);
        if (l < r && f(r - 1, k) <= x - 1 || r > 2 && f(r - 2, k) <= x - 1)
            best = max(best, r - 1);
        if (f((l + r) / 2, k) <= x - 1 || (l + r) / 2 > 1 && f((l + r) / 2 - 1, k) <= x - 1)
            best = max(best, (l + r) / 2);

        if (best == -1)
            best = 1;

        cout << best << "\n";
    }
}