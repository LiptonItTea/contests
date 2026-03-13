#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, l;
    cin >> n >> k >> l;

    vector<int> h (n, 0);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    vector<int> dp (n, 0);
    dp[0] = k;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] - (abs(h[i] - h[i - 1]) > l ? 1 : 0);

        if (i > 1)
            dp[i] = max(dp[i], dp[i - 2] - (h[i - 2] > l ? 1 : 0) - (h[i] > l ? 1 : 0));
    }
    if (n > 1)
        dp[n - 1] = max(dp[n - 1], dp[n - 2] - (h[n - 2] > l ? 1 : 0));

    if (dp[n - 1] >= 0) {
        cout << "YES";
        return 0;
    }

    dp.assign(n, 0);
    dp[1] = k - (h[1] > l ? 1 : 0);
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] - (abs(h[i] - h[i - 1]) > l ? 1 : 0);

        if (i > 2)
            dp[i] = max(dp[i], dp[i - 2] - (h[i - 2] > l ? 1 : 0) - (h[i] > l ? 1 : 0));
    }
    if (n > 1)
        dp[n - 1] = max(dp[n - 1], dp[n - 2] - (h[n - 2] > l ? 1 : 0));
    
    if (dp[n - 1] >= 0) {
        cout << "YES";
        return 0;
    }

    cout << "NO";
}