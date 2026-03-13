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

double eps = 1e-8;

struct Entry {
    int zeros, ones;
    double entropy;
};

vector<int> labels;
vector<vector<int>> links;
vector<Entry> inner;

int counter = 0;

void dfs (int curr) {
    for (int next : links[curr]) {
        dfs(next);
    }

    for (int next : links[curr]) {
        inner[curr].zeros += inner[next].zeros;
        inner[curr].ones += inner[next].ones;
    }

    double p = ((double) inner[curr].ones) / (inner[curr].zeros + inner[curr].ones);
    if (abs(p) < eps || abs(p - 1) < eps) {
        inner[curr].entropy = 0;
        return;
    }

    inner[curr].entropy = -p * log(p) - (1 - p) * log(1 - p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(10);

    int n, k;
    cin >> n >> k;
    
    labels.assign(n, 0);
    inner.assign(2 * n - 1, {0, 0, 0});
    for (int i = 0; i < n; i++){
        cin >> labels[i];

        if (labels[i])
            inner[i].ones = 1;
        else
            inner[i].zeros = 1;
    }

    links.assign(2 * n - 1, vector<int> ());
    for (int i = n; i < 2 * n - 1; i++) {
        int l, r;
        cin >> l >> r;

        links[i].push_back(l - 1);
        links[i].push_back(r - 1);
    }

    dfs(2 * n - 2);

    vector<vector<double>> dp (2 * n - 1, vector<double> (n + 1, INT_MAX));
    for (int i = 0; i < n; i++)
        dp[i][1] = 0;

    for (int v = n; v < 2 * n - 1; v++) {
        int maxs = inner[v].zeros + inner[v].ones;
        int l = links[v][0], r = links[v][1];

        dp[v][1] = inner[v].entropy;
        for (int s = 2; s <= maxs; s++) {
            for (int s1 = 1; s1 < s; s1++) {
                dp[v][s] = min(dp[v][s], dp[l][s1] + dp[r][s - s1]);
            }
        }
    }

    cout << dp[2 * n - 2][k];
}