#include <iostream>
#include <math.h>

using namespace std;

const long long modu = 1000000007;

int main(){
    long long n, l, r;
    cin >> n >> l >> r;

    long long* amounts = new long long[3];
    for (int i = 0; i < 3; i++){
        amounts[i] = floor((r - i) / 3.0) - ceil((l - i) / 3.0) + 1;
        // cout << amounts[i] << " ";
    }
    // cout << '\n';

    long long** dp = new long long*[n];
    dp[0] = new long long[3];
    dp[0][0] = amounts[0];
    dp[0][1] = amounts[1];
    dp[0][2] = amounts[2];
    for (int i = 1; i < n; i++){
        dp[i] = new long long[3];
        dp[i][0] = (((dp[i - 1][0] * amounts[0]) % modu + (dp[i - 1][1] * amounts[2]) % modu) % modu + (dp[i - 1][2] * amounts[1]) % modu) % modu;
        dp[i][1] = (((dp[i - 1][1] * amounts[0]) % modu + (dp[i - 1][0] * amounts[1]) % modu) % modu + (dp[i - 1][2] * amounts[2]) % modu) % modu;
        dp[i][2] = (((dp[i - 1][2] * amounts[0]) % modu + (dp[i - 1][0] * amounts[2]) % modu) % modu + (dp[i - 1][1] * amounts[1]) % modu) % modu;
    }
    cout << dp[n - 1][0];
}