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

// class Colors {
// public:
//     int a, b, c;

//     bool operator()(const Colors& c1, const Colors& c2) const {
//         if (c1.a != c2.a)
//             return c1.a < c2.a;
//         if (c1.b != c2.b)
//             return c1.b < c2.b;
//         return c1.c < c2.c;
//     }
// };

int n, m;

bool flag(int i, int j, vector<vector<int>>& dp) {
    if (i - dp[i][j] < 0 || i + dp[i][j] >= n)
        return false;
    return dp[i][j] <= dp[i - dp[i][j]][j] && dp[i][j] == dp[i + dp[i][j]][j];
}

bool same_scale_color(int i, int j, vector<vector<int>>& dp, vector<string>& field) {
    if (j - 1 < 0 || i - dp[i][j] < 0 || i + dp[i][j] >= n)
        return false;
    return dp[i][j] == dp[i][j - 1] &&
            field[i - dp[i][j]][j] == field[i - dp[i][j]][j - 1] && 
            field[i][j] == field[i][j - 1] && 
            field[i + dp[i][j]][j] == field[i + dp[i][j]][j - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    cin >> n >> m;

    vector<string> field (n);
    for (int i = 0; i < n; i++)
        cin >> field[i];

    vector<vector<int>> dp (n, vector<int> (m, 0));
    for (int j = 0; j < m; j++) {
        dp[0][j] = 1;
        for (int i = 1; i < n; i++) {
            if (field[i][j] == field[i - 1][j])
                dp[i][j] = dp[i - 1][j] + 1;
            else
                dp[i][j] = 1;
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int w = 0;
        for (int j = 0; j < m; j++) {
            if (!flag(i, j, dp)) {
                result += w * (w + 1) / 2;
                w = 0;
                continue;
            }

            if (!same_scale_color(i, j, dp, field)) {
                result += w * (w + 1) / 2;
                w = 1;
                continue;
            }
            
            w++;
        }

        result += w * (w + 1) / 2;
    }

    cout << result;
}