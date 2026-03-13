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

    int n, k;
    cin >> n >> k;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp (n + 1, vector<int> (k + 1));
    vector<int> maxs (k + 1);
    for (int i = 1; i < n + 1; i++) {
        for (int j = k; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j] + a[i - 1];

            if (i > 1) {
                dp[i][j] = max(dp[i][j], dp[i - 2][j] + a[i - 1]);
            }
            if (j < k) {
                dp[i][j] = max(dp[i][j], maxs[j + 1] + a[i - 1]);
            }
        }
        for (int j = k; j >= 0; j--)
            maxs[j] = max(maxs[j], dp[i][j]);
    }

    int result = INT_MIN;
    for (int i = 0; i <= k; i++)
        result = max(result, dp[n][i]);
    cout << result;
}