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
        int n;
        cin >> n;

        vector<int> a (n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> dp (n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i + a[i] + 1 <= n)
                dp[i] = min(dp[i], dp[i + a[i] + 1]);

            if (i + 1 <= n && dp[i + 1] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i + 1]);
        }

        cout << dp[0] << "\n";
    }
}