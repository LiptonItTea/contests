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

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp (n + 1, vector<int> (3, 0));
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            dp[i + 1][0] = dp[i][0] + 1;
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][2] + 1;
        }
        if (a[i] == 0) {
            dp[i + 1][0] = 0;
            dp[i + 1][1] = dp[i][1] + 1;
            dp[i + 1][2] = 0;
        }
        if (a[i] < 0) {
            dp[i + 1][0] = min(dp[i][2], 1);
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][0];
        }
    }

    cout << "done";
}