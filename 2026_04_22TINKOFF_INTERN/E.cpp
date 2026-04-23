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

int calcost(string &s, int i, int j) {
    int cost = 0;
    if ((s[i] == 'T' || s[i] == 'O' || s[i] == 'I') &&
        (s[j] == 'T' || s[j] == 'O' || s[j] == 'I')) {
        
        if (s[i] == s[j]) {
            // do nothing
        }
        else {
            cost = 1;
        }
    }
    else if (s[i] == 'T' || s[i] == 'O' || s[i] == 'I' ||
                s[j] == 'T' || s[j] == 'O' || s[j] == 'I') {
        cost = 1;
    }
    else {
        cost = 2;
    }

    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> dp (n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        if (s[i] != 'T' && s[i] != 'O' && s[i] != 'I')
            dp[i][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        dp[i - 1][i] = min(dp[i][i] + 1, dp[i - 1][i - 1] + 1);

        int cost = calcost(s, i - 1, i);
        dp[i - 1][i] = min(dp[i - 1][i], cost);
    }

    for (int y = 2; y < n; y++) {
        for (int x = 0; x < n - y; x++) {
            int i = x;
            int j = y + x;

            dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);

            int cost = calcost(s, i, j);
            dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + cost);
        }
    }

    cout << dp[0][n - 1];
}