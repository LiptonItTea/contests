#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <list>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <math.h>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll result = LLONG_MIN;
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < i; j++)
            a[j] -= x;
        for (int j = i; j < i + k; j++)
            a[j] += x;
        for (int j = i + k; j < n; j++)
            a[j] -= x;

        vector<ll> dp (n);
        dp[0] = a[0];
        ll curr_result = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + a[i], a[i]);
            curr_result = max(dp[i], curr_result);
        }
        result = max(result, curr_result);

        for (int j = 0; j < i; j++)
            a[j] += x;
        for (int j = i; j < i + k; j++)
            a[j] -= x;
        for (int j = i + k; j < n; j++)
            a[j] += x;
    }

    cout << max(0ll, result);
}