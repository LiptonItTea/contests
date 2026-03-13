#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string s = b + '#' + a;

    //last col will be 0 due to #
    vector<int> bpi (b.size(), 0);
    for (int i = 1; i < s.size(); i++) {
        int j = bpi[i - 1];
        while (j > 0 && b[j] != b[i])
            j = bpi[j - 1];
        
        if (b[j] == b[i])
            j++;
        bpi[i] = j;
    }
    vector<vector<int>> next (b.size() + 1, vector<int> (26, -1));
    for (int i = 0; i < b.size() + 1; i++) {
        for (int k = 0; k < 26; k++) {
            char c = 'a' + k;

            int j = i;
            while (j > 0 && s[j] != c)
                j = bpi[j - 1];
            
            if (s[j] == c)
                j++;
            next[i][k] = j;
        }
    }

    vector<vector<int>> dp (s.size(), vector<int> (b.size() + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = 0; j < b.size() + 1; j++) {
            if (s[i + 1] == '#') {
                dp[i + 1][0] = 0; // exception
            }
            else if (s[i + 1] != '?') {
                int pi_from_here = next[j][s[i + 1] - 'a'];
                dp[i + 1][pi_from_here] = max(dp[i + 1][pi_from_here], dp[i][j]);
            }
            else {
                for (char k = 'a'; k <= 'z'; k++){
                    int pi_from_here = next[j][k - 'a'];
                    dp[i + 1][pi_from_here] = max(dp[i + 1][pi_from_here], dp[i][j]);
                }
            }
        }
        if (dp[i + 1][b.size()] != -1)
            dp[i + 1][b.size()]++;
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < b.size() + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}