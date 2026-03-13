#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, k;
    cin >> n >> k;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = i; l < n + 1; l++)
                dp[l] = (dp[l] + dp[l - i]) % mod;
        }
    }
    
    cout << dp[n];
}