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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll n, x;
    cin >> n >> x;

    if (n == 1) {
        cout << x;
        return 0;
    }

    vector<ll> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> k (n - 1);    
    vector<ll> d (n);
    for (int i = 0; i < n - 1; ++i) {
        k[i] = a[i + 1] / a[i];
        d[i] = (x / a[i]) % k[i];
    }
    d[n - 1] = x / a[n - 1];

    ll dp0 = d[n - 1];
    ll dp1 = d[n - 1] + 1;

    for (int i = n - 2; i >= 0; i--) {
        ll ndp0 = min(d[i] + dp0, (k[i] - d[i]) + dp1);
        ll ndp1 = min((d[i] + 1) + dp0, (k[i] - (d[i] + 1)) + dp1);
        dp0 = ndp0;
        dp1 = ndp1;
    }

    cout << dp0;
}