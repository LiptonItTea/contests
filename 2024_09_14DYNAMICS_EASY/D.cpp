#include <iostream>

using namespace std;

int main(){
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);

    int** field = new int*[8];
    for (int i = 0; i < 8; i++){
        field[i] = new int[8];
        for (int j = 0; j < 8; j++){
            cin >> field[i][j];
        }
    }

    int** dp = new int*[8];
    for (int i = 0; i < 8; i++){
        dp[i] = new int[8];
    }
    dp[7][0] = 0;

    //down line
    for (int i = 1; i < 8; i++){
        dp[7][i] = dp[7][i - 1] + field[7][i];
    }
    //left line
    for (int i = 6; i >= 0; i--){
        dp[i][0] = dp[i + 1][0] + field[i][0];
    }

    //go
    for (int i = 6; i >= 0; i--){
        for (int j = 1; j < 8; j++){
            dp[i][j] = min(dp[i][j - 1], min(dp[i + 1][j], dp[i + 1][j - 1])) + field[i][j];
        }
    }

    cout << dp[0][7];
}