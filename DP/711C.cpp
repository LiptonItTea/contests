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

        int n, m, k;
        cin >> n >> m >> k;

        vector<int> c (n);
        bool all_colored = true;
        for (int i = 0; i < n; i++){
            cin >> c[i];

            if (c[i] == 0)
                all_colored = false;
        }

        vector<vector<ll>> p (n, vector<ll> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> p[i][j];

        vector<vector<vector<ll>>> dp (n + 1, vector<vector<ll>> (k + 1, vector<ll> (m, INT_MAX * 1000ll)));
        if (c[0] == 0)
            for (int l = 0; l < m; l++)
                dp[1][1][l] = p[0][l];
        else
            dp[1][1][c[0] - 1] = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (c[i] == 0) {
                    for (int l = 0; l < m; l++) {
                        for (int x = 0; x < m; x++) {
                            if (x == l)
                                dp[i + 1][j + 1][l] = min(dp[i + 1][j + 1][l], dp[i][j + 1][x] + p[i][l]);
                            else
                                dp[i + 1][j + 1][l] = min(dp[i + 1][j + 1][l], dp[i][j][x] + p[i][l]);
                        }
                    }
                }
                else {
                    for (int x = 0; x < m; x++) {
                        if (c[i] - 1 == x)
                            dp[i + 1][j + 1][c[i] - 1] = min(dp[i + 1][j + 1][c[i] - 1], dp[i][j + 1][x]);
                        else
                            dp[i + 1][j + 1][c[i] - 1] = min(dp[i + 1][j + 1][c[i] - 1], dp[i][j][x]);
                    }
                }
            }
        }

        ll best = INT_MAX * 1000ll;
        for (int l = 0; l < m; l++)
            best = min(best, dp[n][k][l]);

        if (best == INT_MAX * 1000ll)
            cout << -1;
        else
            cout << best;
    }