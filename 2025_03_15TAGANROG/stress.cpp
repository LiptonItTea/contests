#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <random>

#define ll long long

using namespace std;

bool first(int n, int k, int l, vector<int>& h) {
    
    vector<int> dp (n, 0);
    dp[0] = k;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] - (abs(h[i] - h[i - 1]) > l ? 1 : 0);

        if (i > 1)
            dp[i] = max(dp[i], dp[i - 2] - (h[i - 2] > l ? 1 : 0) - (h[i] > l ? 1 : 0));
    }

    if (dp[n - 1] >= 0) {
        return true;
    }

    dp.assign(n, 0);
    dp[1] = k - (h[1] > l ? 1 : 0);
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] - (abs(h[i] - h[i - 1]) > l ? 1 : 0);

        if (i > 2)
            dp[i] = max(dp[i], dp[i - 2] - (h[i - 2] > l ? 1 : 0) - (h[i] > l ? 1 : 0));
    }
    
    if (dp[n - 1] >= 0) {
        return true;
    }

    return false;
}

bool second(int n, int k, int l, vector<int>& h) {
    vector dp(n + 1, vector(2, LLONG_MAX));
 
    dp[1][0] = 0;
    if (n >= 2) {
        dp[2][1] = min(dp[2][1], (h[2] <= l ? 0LL : 1LL));
    }
 
    for (int i = 1; i <= n; i++) {
        ll best = min(dp[i][0], dp[i][1]);
        if (i + 1 <= n) {
            ll cost_direct = (llabs(h[i] - h[i + 1]) <= l ? 0 : 1);
            dp[i + 1][0] = min(dp[i + 1][0], best + cost_direct);
        }
        if (i + 2 <= n && h[i] <= l) {
            ll cost_jump = h[i + 2] <= l ? 0 : 1;
            dp[i + 2][1] = min(dp[i + 2][1], best + cost_jump);
        }
    }
 
    ll ans = min(dp[n][0], dp[n][1]);
    // cout << (ans <= k ? "YES" : "NO") << "\n";
    return (ans <= k ? true : false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 1000;
    int k = 100;
    int l = 20;

    random_device dev;
    mt19937 rng (dev());

    uniform_int_distribution<mt19937::result_type> dist (1, 100);
    vector<int> h (n, 0);
    while (true) {
        for (int i = 0; i < n; i++) {
            h[i] = dist(rng);
        }

        if (first(n, k, l, h) != second(n, k, l, h)) {
            cout << "FOUND!!!!!!!!!!!!!!!!!!!\n";
            for (int i = 0; i < n; i++) {
                cout << h[i] << " ";
            }
            break;
        }
        else {
            cout << "OK " << h[0] << " " << h[1] << "\n";
        }
    }
}