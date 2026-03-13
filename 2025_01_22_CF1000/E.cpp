#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<vector<int>> links;
vector<ll> d;
vector<ll> sbtrs;
vector<ll> alld;
vector<ll> prefd;
vector<ll> lcasum;

ll dfs (int curr, int prev, int depth) {
    ll subtree = 1;
    for (int next : links[curr]) {
        if (next == prev)
            continue;
        
        subtree += dfs(next, curr, depth + 1);
    }
    sbtrs[curr] = subtree;
    d[curr] = depth;
    alld[depth] += 1;
    return subtree;
}

void countlca(int curr, int prev) {
    if (curr != 0)
        lcasum[prev] += sbtrs[curr] * (sbtrs[prev] - 1 - sbtrs[curr]);
    for (int next : links[curr]) {
        if (next == prev)
            continue;
        
        countlca(next, curr);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;
        
        links.assign(n, vector<int> ());
        sbtrs.assign(n, 0);
        d.assign(n, 0);
        alld.assign(n, 0);
        prefd.assign(n + 1, 0);
        lcasum.assign(n, 0);
        
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;

            links[a - 1].push_back(b - 1);
            links[b - 1].push_back(a - 1);
        }

        dfs(0, -1, 0);
        for (int i = n - 1; i >= 0; i--)
            prefd[i] = prefd[i + 1] + alld[i];
        
        ll result = 0;
        for (int u = 0; u < n; u++) { // 2 * min(d[u], d[v])
            result += 2 * d[u] * (prefd[d[u]] - sbtrs[u]);
        }
        for (ll k = 0; k < n - 1; k++) { // fixing dublicates
            result -= k * (prefd[k] - prefd[k + 1]) * (prefd[k] - prefd[k + 1] - 1ll);
        }
        countlca(0, -1);
        ll lca = 0;
        for (int w = 0; w < n; w++) {
            lca += (2ll * d[w] + 1ll) * lcasum[w];
        }
        result -= lca / 2ll;

        cout << result << "\n";
    }
}