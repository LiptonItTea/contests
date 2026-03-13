#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int** array = new int*[n];
    for (int i = 0; i < n; i++){
        array[i] = new int[i + 1];
        for (int j = 0; j < i + 1; j++){
            cin >> array[i][j];
        }
    }

    int** dp = new int*[n];
    dp[0] = new int[1];
    dp[0][0] = array[0][0];
    for (int i = 1; i < n; i++){
        dp[i] = new int[i + 1];
        for (int j = 0; j < i + 1; j++){
            dp[i][j] = INT_MIN;
            if(j > 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + array[i][j]);
            }
            if(j < i){
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + array[i][j]);
            }
        }
    }

    int maxCost = INT_MIN;
    for (int i = 0; i < n; i++){
        maxCost = max(maxCost, dp[n - 1][i]);
    }

    cout << maxCost;
}