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

ll mod = 1000000007;

vector<ll> factDict {1, 1, 2};
ll factMod(ll n) {
    if (n < factDict.size())
        return factDict[n];
    
    for (ll i = factDict.size(); i <= n; i++) {
        factDict.push_back((*factDict.rbegin() * i) % mod);
    }
    return factDict[n];
}

ll fastPowMod(ll num, ll pow) {
    if (pow == 0)
        return 1;

    if (pow % 2 == 0) {
        ll result = fastPowMod(num, pow / 2);
        return (result * result) % mod;
    }
    return (num * fastPowMod(num, pow - 1)) % mod;
}

ll invMod(ll n) {
    return fastPowMod(n, mod - 2);
}

ll combMod(ll k, ll n) {
    if (k > n)
        return 0;
    if (k < 0 || n < 0)
        return 0;

    ll result = ((factMod(n) * invMod(factMod(n - k))) % mod * invMod(factMod(k))) % mod;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        ll n;
        cin >> n;

        ll result = 1; // if i=0, result+=1 (exception)
        for (ll i = 1; i <= n; i++) {
            ll k = min(2 * i + 1, n);
            
            for (ll j = 0; j <= i; j++) {
                ll c = (combMod(i - j, k) * combMod(j, n - k)) % mod;
                result = (result + (c * (2 * i + 1 - j)) % mod) % mod;
            }
        }

        cout << result << "\n";
    }
}