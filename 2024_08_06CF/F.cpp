#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll mod = 1000000007;

vector<ll> fact {1};
ll factMod(ll n) {
    while (n >= fact.size())
        fact.push_back((fact[fact.size() - 1] * fact.size()) % mod);
    
    return fact[n];
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

ll inverseMod(ll num) {
    return fastPowMod(num, mod - 2);
}

ll choose(ll k, ll n) {
    if (n < k)
        return 0;
    if (n < 0)
        return 0;
    if (k == 0)
        return 1;
    if (k < 0)
        return 0;
    return ((factMod(n) * inverseMod(factMod(k))) % mod * inverseMod(factMod(n - k))) % mod;
}

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, k;
        cin >> n >> k;

        int count1 = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a; 

            if (a == 1)
                count1++;
        }
        
        ll result = 0;
        for (int ppcnt = k/2 + 1; ppcnt <= count1; ppcnt++) {
            ll amount = (choose(k - ppcnt, n - count1) * choose(ppcnt, count1)) % mod;

            result = (result + amount) % mod;
        }
        if (result < 0)
            result += mod;

        cout << result << "\n";
    }
}