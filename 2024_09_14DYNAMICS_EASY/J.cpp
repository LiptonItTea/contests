#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* dp = new int[n + 1];
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i < n + 1; i++){
        dp[i] = 3 * dp[i - 1] - dp[i - 2];
    }

    cout << dp[n];
}