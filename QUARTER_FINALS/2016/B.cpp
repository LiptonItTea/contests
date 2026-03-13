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
    int maxa = INT_MIN; // better debugging
    for (int i = 0; i < n; i++){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    vector<vector<int>> dp (n + 1, vector<int> (maxa + 1, INT_MAX));
    // init
    for (int j = 0; j < maxa + 1; j++)
        dp[0][j] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < maxa + 1; j++) {
            int best_prev = INT_MAX;
            for (int l = max(0, j - k); l <= min(maxa, j + k); l++) {
                best_prev = min(best_prev, dp[i][l]);
            }

            if (best_prev != INT_MAX)
                dp[i + 1][j] = abs(a[i] - j) + best_prev;
        }
    }

    int best_answ = INT_MAX;
    for (int j = 0; j < maxa + 1; j++)
        best_answ = min(best_answ, dp[n][j]);

    cout << best_answ;
}