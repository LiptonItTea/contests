#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int>>& dp, vector<vector<int>>& c, int l, int r){
    if(dp[l][r] != 0)
        return;
    
    for (int m = l; m < r; m++){
        solve(dp, c, l, m);
        solve(dp, c, m + 1, r);

        // for (int i = 0; i < dp.size(); i++){
        //     for (int j = 0; j < dp.size(); j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // for (int i = 0; i < dp.size(); i++){
        //     for (int j = 0; j < dp.size(); j++){
        //         cout << c[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        if(c[l][m] != 0 && c[m + 1][r] != 0 && c[l][m] == c[m + 1][r]){
            dp[l][r] = 1;
            c[l][r] = c[l][m] + 1;
        }
        else{
            if(dp[l][r] == 0)
                dp[l][r] = dp[l][m] + dp[m + 1][r];
            else
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
        }
    }
}

int main () {
    int n;
    cin >> n;

    int* array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    vector<vector<int>> dp;
    vector<vector<int>> c;
    for (int i = 0; i < n; i++){
        vector<int> dumb;
        vector<int> cumb;
        for (int i = 0; i < n; i++){
            dumb.push_back(0);
            cumb.push_back(0);
        }
        dp.push_back(dumb);
        c.push_back(cumb);

        dp[i][i] = 1;
        c[i][i] = array[i];
    }

    solve(dp, c, 0, n - 1);
    cout << dp[0][n - 1];
}