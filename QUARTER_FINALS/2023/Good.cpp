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

    vector<vector<ll>> dp (5, vector<ll> (100, 0)); // dp[l][s]
    vector<string> all (n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        all[i] = s;

        int full_sum = 0;
        for (int j = 0; j < s.size(); j++)
            full_sum += s[j] - '0';

        int pref = 0;
        for (int j = 0; j < s.size(); j++) {
            pref += s[j] - '0';
            
            if (2 * j + 1 < s.size())
                continue;

            if (pref - (full_sum - pref) < 0)
                continue;
            
            if (2 * j + 1 - s.size() == 0)
                dp[0][(pref - (full_sum - pref))]++;
            if (2 * j + 1 - s.size() == 1)
                dp[1][(pref - (full_sum - pref))]++;
            if (2 * j + 1 - s.size() == 2)
                dp[2][(pref - (full_sum - pref))]++;
            if (2 * j + 1 - s.size() == 3)
                dp[3][(pref - (full_sum - pref))]++;
            if (2 * j + 1 - s.size() == 4)
                dp[4][(pref - (full_sum - pref))]++;
        }
        pref = 0;
        for (int j = s.size() - 1; j >= 1; j--) {
            pref += s[j] - '0';
            
            if (2 * j + 1 > s.size())
                continue;

            if (pref - (full_sum - pref) < 0)
                continue;
            
            if (s.size() - (2 * j + 1) == 0)
                dp[0][(pref - (full_sum - pref))]++;
            if (s.size() - (2 * j + 1) == 1)
                dp[1][(pref - (full_sum - pref))]++;
            if (s.size() - (2 * j + 1) == 2)
                dp[2][(pref - (full_sum - pref))]++;
            if (s.size() - (2 * j + 1) == 3)
                dp[3][(pref - (full_sum - pref))]++;
            if (s.size() - (2 * j + 1) == 4)
                dp[4][(pref - (full_sum - pref))]++;
        }
    }

    ll result = 0;
    for (int i = 0; i < n; i++) {
        string s = all[i];
        int pref = 0;
        for (int j = 0; j < s.size(); j++)
            pref += s[j] - '0';

        result += dp[s.size() - 1][pref];
    }

    cout << result;
}