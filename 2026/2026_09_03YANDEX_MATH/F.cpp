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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(5);

    double p;
    int n;
    cin >> p >> n;

    vector<double> dp(n + 1, 0.0);
    dp[1] = 1.0 - p;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            dp[i] += p * dp[j] * dp[i - j];

    cout << dp[n];
}