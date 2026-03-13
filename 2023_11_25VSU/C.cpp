#include <iostream>

using namespace std;

int main(){
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    int** dp = new int*[n];
    for (int i = 0; i < n; i++){
        dp[i] = new int[m];
        for (int j = 0; j < m; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            //2 down 1 right
            if(i >= 2 && j >= 1){
                dp[i][j] += dp[i - 2][j - 1];
            }
            //1 down 2 right
            if(i >= 1 && j >= 2){
                dp[i][j] += dp[i - 1][j - 2];
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    cout << dp[n - 1][m - 1];
}