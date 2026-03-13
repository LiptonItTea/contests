#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<vector<long long>> dp (n, vector<long long> (n));
    for (int i = 0; i < n; i++){
        long long costMult = (n - i);
        for (int j = 0; i + j < n; j++){
            if(i == 0)
                dp[j][i + j] = costMult * a[j];
            else
                dp[j][i + j] = max(dp[j + 1][i + j] + costMult * a[j], dp[j][i + j - 1] + costMult * a[i + j]);
        }
    }
    cout << dp[0][n - 1];
}