#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

ll mod = 1000000007;

bool desc(ll a, ll b) {
    return a > b;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // cout << setprecision(9) << fixed;

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a (n, 0);
        ll result = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            result = (result + a[i]) % mod;
        }
        sort(a.begin(), a.end(), desc);

        vector<ll> delta (n, 0);
        ll sumdelta = 0;
        for (ll i = 0; i < n - 2; i++) {
            // result += (a[i] + delta[i]) * max(0, k - i - 1);
            // delta[i] += a[i] + delta;
            // if (i >= k)
            //     delta -= a[i - k];
            result = (result + (((a[i] + sumdelta) % mod) * max(0ll, min(k - 1ll, n - 2ll - i))) % mod) % mod;
            if (i + 1 < n)
                delta[i + 1] = (delta[i + 1] + (a[i] + sumdelta) % mod) % mod;
            if (i + 1 + k < n)
                delta[i + 1 + k] = (delta[i + 1 + k] - (a[i] + sumdelta) % mod) % mod;
            sumdelta = (sumdelta + delta[i + 1]) % mod;
        }

        if (result < 0)
            result += mod;
        cout << result << '\n';
    }
}