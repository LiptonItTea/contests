#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("peacefulsets.in", "r", stdin);
    freopen("peacefulsets.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<long long>> dp (12, vector<long long> (n + 1));
    dp[0][0] = 1;

    for (int i = 1; i < n + 1; i++){
        for (int j = 0, power = 1; j < 12 && power <= i; j++, power = (power << 1) | 1){
            for (int k = 0; k <= j; k++){
                dp[j][i] += dp[k][i - power];
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < 12; i++){
        result += dp[i][n];
    }

    cout << result;
}