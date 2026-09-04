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

    int n;
    cin >> n;

    int n2 = 1 << n;

    vector<vector<ll>> c (n2, vector<ll> (n + 1));
    for (int i = 0; i < n2; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    vector<ll> dp (n2, 0);
    vector<ll> ndp (n2);

    for (int r = 1; r <= n; r++) {
        int block_size = 1 << r;
        int half = block_size / 2;

        for (int start = 0; start < n2; start += block_size) {
            int mid = start + half;
            int finish = start + block_size;

            ll best_left = 0;
            ll best_right = 0;

            for (int i = start; i < mid; i++) {
                ll reward = (r == 1 ? 0 : c[i][r - 1]);
                best_left = max(best_left, dp[i] + reward);
            }

            for (int i = mid; i < finish; i++) {
                ll reward = (r == 1 ? 0 : c[i][r - 1]);
                best_right = max(best_right, dp[i] + reward);
            }

            for (int i = start; i < mid; i++)
                ndp[i] = dp[i] + best_right;
            for (int i = mid; i < finish; i++)
                ndp[i] = dp[i] + best_left;
        }

        dp.swap(ndp);
    }

    ll best = 0;
    for (int i = 0; i < n2; i++)
        best = max(best, dp[i] + c[i][n]);

    cout << best;
}