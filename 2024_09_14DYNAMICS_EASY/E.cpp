#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int** array = new int*[n];
    for (int i = 0; i < n; i++){
        array[i] = new int[i + 1];
        for (int j = 0; j < i + 1; j++)
            cin >> array[i][j];
    }

    int** dp = new int*[n];
    for (int i = 0; i < n; i++){
        dp[i] = new int[i + 1];
    }

    dp[0][0] = array[0][0];
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i + 1; j++){
            if(j == i)
                dp[i][j] = dp[i - 1][j - 1] + array[i][j];
            else if(j == 0)
                dp[i][j] = dp[i - 1][j] + array[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1] + array[i][j], dp[i - 1][j] + array[i][j]);
        }
    }

    int maxPoints = INT_MIN;
    for (int i = 0; i < n; i++){
        maxPoints = max(maxPoints, dp[n - 1][i]);
    }

    cout << maxPoints;
}