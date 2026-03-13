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

vector<ll> factDict {1, 1, 2};
vector<ll> invFactDict {0, 0, 0}; // idk, in main
ll factMod(ll n) {
    if (n < factDict.size())
        return factDict[n];
    
    for (ll i = factDict.size(); i <= n; i++) {
        factDict.push_back((*factDict.rbegin() * i) % mod);
        invFactDict.push_back(invMod(*factDict.rbegin()));
    }
    return factDict[n];
}

ll combMod(ll k, ll n) {
    if (k > n)
        return 0;
    if (k < 0 || n < 0)
        return 0;

    ll result = ((factMod(n) * invFactDict[n - k]) % mod * invFactDict[k]) % mod;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    factDict.reserve(5000);
    invFactDict[0] = invMod(factDict[0]);
    invFactDict[1] = invMod(factDict[1]);
    invFactDict[2] = invMod(factDict[2]);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        ll result = 0;
        for (int k = 0; k <= n; k++) { // todo k=0?
            if (2 * k >= n) {
                result = (result + (combMod(k, n) * (2 * k + 1)) % mod) % mod;
            }
            else { // 2 * k < n
                for (int m = k + 1; m <= 2 * k + 1; m++) {
                    result = (result + ((combMod(m - 1 - k, m - 1) * combMod(2 * k + 1 - m, n - m)) % mod * m) % mod) % mod;
                }
            }
        }

        cout << result << "\n";
    }
}