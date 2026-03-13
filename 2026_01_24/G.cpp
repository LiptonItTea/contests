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

ll diag(ll i) {
    if (i % 2 == 0)
        return (i - 1) / 4 * 2 + 2;
    else
        return i / 4 * 2 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll n, k;
    cin >> n >> k;

    if (k > 2 * n - 1) {
        cout << 0;
        return 0;
    }

    vector<vector<ll>> dp (n * 2, vector<ll> (k + 2));
    for (ll i = 0; i < n * 2; i++)
        dp[i][0] = 1;
    
    dp[1][1] = 1;
    for (ll i = 2; i < n * 2; i++) {
        for (ll j = 1; j <= k; j++) {
            dp[i][j] = (dp[i - 2][j] + (dp[i - 2][j - 1] * (diag(i) - j + 1)) % mod) % mod;
            if (dp[i][j] < 0)
                dp[i][j] += mod;
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= k; i++) {
        ans = (ans + (dp[n * 2 - 1][i] * dp[n * 2 - 2][k - i]) % mod) % mod;
        if (ans < 0)
            ans += mod;
    }

    cout << ans;
}