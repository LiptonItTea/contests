#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m, k;
        cin >> n >> m >> k;

        string a;
        cin >> a;

        vector<int> dp (n + 2, -1);
        dp[0] = k;
        for (int i = 1; i < n + 2; i++) {
            if (a[i - 1] == 'C')
                continue;
            
            //previous water|log
            if (i - 2 >= 0 && a[i - 2] == 'W'){
                dp[i] = max(dp[i], dp[i - 1]);
            }
            
            //jump
            for (int j = 1; j <= min(m, i); j++) {
                if (i - j == 0 || a[i - 1 - j] == 'L')
                    dp[i] = max(dp[i], dp[i - j]);
            }
            
            if (a[i - 1] == 'W')
                dp[i]--;
        }
        if (dp[n + 1] > -1) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}