#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll mod = 1000000007;

ll fastPow(ll num, ll pow) {
    if (pow == 0)
        return 1;
    
    if (pow % 2 == 0) {
        ll result = fastPow(num, pow / 2);
        return (result * result) % mod;
    }
    return (num * fastPow(num, pow - 1)) % mod;
}

vector<int> fact {1};
vector<int> inv_fact{1};
ll get_fact(ll n) {
    if (n < fact.size())
        return fact[n];
    
    while (n >= fact.size()){
        fact.push_back((fact[fact.size() - 1] * fact.size()) % mod);
        inv_fact.push_back(fastPow(fact[fact.size() - 1], mod - 2));
    }
    
    return fact[n];
}

ll inverse_fact(ll n) {
    return inv_fact[n];
}

ll choose(ll n, ll k) {
    if (n < 0)
        return 0;
    if (k < 0)
        return 0;
    if (n < k)
        return 0;
    return (((get_fact(n) * inverse_fact(k)) % mod) * inverse_fact(n - k)) % mod;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        ll n;
        cin >> n;

        ll result = 0;
        for (ll sz = 0; sz <= n; sz++) { // size of subset
            if (2 * sz >= n){
                ll delta = ((2 * sz + 1) * choose(n, sz)) % mod;
                result = (result + delta) % mod;
                continue;
            }

            for (ll mex = sz + 1; mex <= 2 * sz + 1; mex++) { // actual value of mex
                ll amount = (choose(mex - 1, mex - 1 - sz) * choose(n - mex, 2 * sz + 1 - mex)) % mod;
                ll delta = (amount * mex) % mod;
                result = (result + delta) % mod;
            }
        }

        cout << result << "\n";
    }
}