#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <list>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <math.h>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pp (n + 1);
    for (int i = 1; i < n + 1; i++)
        pp[i] = pp[i - 1] + a[i - 1] + x;
    
    vector<ll> np (n + 1);
    for (int i = 1; i < n + 1; i++)
        np[i] = np[i - 1] + a[i - 1] - x;
        
    ll result = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll best_pref = INT_MAX;
        for (int j = max(-1ll, i - k); j < i; j++)
            best_pref = min(best_pref, pp[j + 1]);

        result = max(result, pp[i + 1] - best_pref);
    }

    ll nresult = LLONG_MIN;
    ll best_pref = LLONG_MAX;
    for (int i = k; i < n; i++) {
        best_pref = min(best_pref, np[i - k]);
        nresult = max(nresult, np[i + 1] - best_pref);
    }
    nresult += 2 * k * x;

    cout << max(0ll, max(result, nresult));
}