#include <iostream>

using namespace std;

int main () {
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);

    int n;
    cin >> n;

    int* array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    int* dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = array[0];
    for (int i = 2; i < n + 1; i++){
        dp[i] = max(dp[i - 1], dp[i - 2]);
        dp[i] += array[i - 1];
    }

    cout << dp[n];
}