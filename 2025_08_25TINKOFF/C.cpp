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

vector<ll> factArray {1, 1, 2};
ll factMod(int n) {
    if (n < factArray.size())
        return factArray[n];
    
    while (n >= factArray.size())
        factArray.push_back((factArray[factArray.size() - 1] * factArray.size()) % mod);
    return factArray[n];
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

ll invMod(ll num) {
    return fastPowMod(num, mod - 2);
}

ll combs(ll k, ll n) {
    if (n == 0)
        return 1;
    if (k == 0 || k == n)
        return 1;
    if (k > n)
        return 0;
    
    return ((factMod(n) * invMod(factMod(k))) % mod * invMod(factMod(n - k))) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<int> a (n);
    map<int, int> amounts;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        amounts[a[i]]++;
    }
    
    auto it = amounts.begin();
    ll result = 0;
    for (int i = 0; it != amounts.end(); it++, i++) {
        ll delta = 0;
        for (int j = 1; j <= amounts.size() - i; j++) {
            delta += combs(j - 1, amounts.size() - i - 1);
        }

        result += delta * it->second;
    }

    cout << result;
}