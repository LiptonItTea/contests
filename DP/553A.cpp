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

vector<ll> fact {1, 1, 2};
ll factMod(ll n) {
    while (n >= fact.size())
        fact.push_back(((*fact.rbegin()) * fact.size()) % mod);
    return fact[n];
}

ll fastPow(ll num, ll pow) {
    if (pow == 0)
        return 1;

    if (pow % 2 == 0) {
        ll result = fastPow(num, pow / 2);
        return (result * result) % mod;
    }
    return (num * fastPow(num, pow - 1)) % mod;
}

ll invMod(ll num) {
    return fastPow(num, mod - 2);
}

ll choice(ll n, ll k) {
    return ((factMod(n) * invMod(factMod(k))) % mod * invMod(factMod(n - k))) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int k;
    cin >> k;

    vector<int> c (k);
    for (int i = 0; i < k; i++)
        cin >> c[i];

    vector<int> pref (k);
    pref[0] = c[0];
    for (int i = 1; i < k; i++)
        pref[i] = pref[i - 1] + c[i];

    ll result = 1;
    for (int i = 1; i < k; i++) {
        ll prev = pref[i - 1];

        ll bin = choice(prev + c[i] - 1, c[i] - 1);
        result = (result * bin) % mod;
    }

    cout << result;
}