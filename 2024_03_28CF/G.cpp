#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <intrin.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<string> sg (n, "");
        vector<string> sw (n, "");
        vector<string> mapping;
        for (int i = 0; i < n; i++) {
            string g, w;
            cin >> g >> w;

            mapping.push_back(g);
            mapping.push_back(w);           
            sg[i] = g;
            sw[i] = w;
        }
        sort(mapping.begin(), mapping.end());
        mapping.erase(unique(mapping.begin(), mapping.end()), mapping.end());

        // map strings to int
        vector<int> g (n, -1);
        vector<int> w (n, -1);
        for (int i = 0; i < n; i++) {
            g[i] = lower_bound(mapping.begin(), mapping.end(), sg[i]) - mapping.begin();
            w[i] = lower_bound(mapping.begin(), mapping.end(), sw[i]) - mapping.begin();
        }

        vector<vector<bool>> dp (1 << n, vector<bool> (n, false));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = true;
        }
        for (int mask = 1; mask < (1 << n); mask++) { // mask of included songs
            for (int i = 0; i < n; i++) { // last included song
                if (dp[mask][i]) // initial state
                    continue;
                // need to generate mask from which we arrived here
                // though need to set i's bit of mask to 0
                if (((mask >> i) & 1) == 0) // if i's bit is 0, the transition is wrong
                    continue;

                int parent_mask = mask - (1 << i);
                for (int j = 0; j < n; j++) { // iterate over possible last included songs of parent mask
                    if (parent_mask >> j & 1 == 0) // same
                        continue;
                    
                    if (g[i] == g[j] || w[i] == w[j])
                        dp[mask][i] = dp[mask][i] || dp[parent_mask][j];
                }
            }
        }

        int max_ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++){ 
                if (!dp[mask][i])
                    continue;
                max_ans = max(max_ans, (int) __popcnt(mask));
            }
        }
        
        cout << n - max_ans << "\n";
    }
}