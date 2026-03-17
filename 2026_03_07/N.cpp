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

    vector<string> s (n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<int> lcp (n, 0);  
    for (int j = 0; j < n; j++)
        while (lcp[j] < s[j].size() && lcp[j] < s[0].size() && s[j][lcp[j]] == s[0][lcp[j]])
            lcp[j]++;

    vector<int> dp (s[0].size() + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < dp.size() - 1; i++) {
        // recalculate minlcp
        int minlcp = INT_MAX;
        for (int j = 0; j < n; j++)
            if (lcp[j] >= i)
                minlcp = min(minlcp, lcp[j]);
        
        //calculate dp
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (minlcp != INT_MAX && minlcp > 0)
            dp[minlcp] = min(dp[minlcp], dp[i] + 1);
    }

    cout << dp[dp.size() - 1];
}