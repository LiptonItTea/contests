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

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp (n, vector<int> (n, 0));
    // base 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        for (int j = 1; j < n; j++) {
            if (i - j < 0 || i + j >= n)
                break;

            if (s[i - j] == s[i + j])
                dp[i - j][i + j] = 1;
            else
                break;
        }
    }

    // base 2
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i])
            continue;
        
        dp[i - 1][i] = 1;
        for (int j = 1; j < n; j++) {
            if (i - 1 - j < 0 || i + j >= n)
                break;

            if (s[i - 1 - j] == s[i + j])
                dp[i - 1 - j][i + j] = 1;
            else
                break;
        }
    }

    vector<vector<int>> prefv (n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (j == n - 1) {
                prefv[j][i] = dp[j][i];
                continue;
            }

            prefv[j][i] = prefv[j + 1][i] + dp[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j == 0) {
                dp[i][j] = prefv[i][j];
                continue;
            }

            dp[i][j] = dp[i][j - 1] + prefv[i][j];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << dp[l - 1][r - 1] << "\n";
    }
}