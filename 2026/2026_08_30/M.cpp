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

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        string x, y;
        cin >> x >> y;

        int n = x.size();

        vector<vector<int>> dp (n + 1, vector<int> (2, INT_MAX - 10));
        dp[0][0] = 0;
        dp[0][1] = INT_MAX - 10;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int yprev = j ^ k;
                    
                    int curr = dp[i][yprev];
                    // dp[i][j] = dp[i - 1][yprev];
                    if (y[i] - '0' != j)
                        curr++;
                    if (x[i] - '0' != k)
                        curr++;
                    dp[i + 1][j] = min(dp[i + 1][j], curr);
                }
            }
        }

        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
}