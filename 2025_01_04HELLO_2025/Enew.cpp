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

struct Edge {
    int u, v, w;
};

bool compare_edges(Edge &e1, Edge &e2) {
    return e1.w < e2.w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<vector<vector<int>>> dp (1, vector<vector<int>> (n, vector<int>(n, INT_MAX)));
        for (int i = 0; i < n; i++)
            dp[0][i][i] = 0;
        vector<Edge> edges (m);
        for (int i = 0; i < m; i++) {
            int v, u, w;
            cin >> v >> u >> w;

            dp[0][v - 1][u - 1] = 1;
            dp[0][u - 1][v - 1] = 1;
            
            edges[i].u = u - 1;
            edges[i].v = v - 1;
            edges[i].w = w;
        }
        sort(edges.begin(), edges.end(), compare_edges);

        for (int k = 0; k < n; k++) { // init
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[0][i][k] != INT_MAX && dp[0][k][j] != INT_MAX && 
                        dp[0][i][j] > dp[0][i][k] + dp[0][k][j]) {

                        dp[0][i][j] = dp[0][i][k] + dp[0][k][j];
                        dp[0][j][i] = dp[0][i][j];
                    }
                }
            }
        }

        vector<int> changedIndex;
        for (int e = 0; e < m; e++) { // iterate over dynamic - remove e'th edge
            int a = edges[e].u;
            int b = edges[e].v;

            if ((*dp.rbegin())[a][b] == 0) {
                continue;
            }
            dp.push_back(vector<vector<int>> (n, vector<int> (n, INT_MAX)));
            changedIndex.push_back(e);

            auto it = dp.rbegin();
            vector<vector<int>> &curr = *(it++);
            vector<vector<int>> &prev = *it;
            for (int i = 0; i < n; i++) { // recalculate weights
                for (int j = 0; j < n; j++) {
                    curr[i][j] = prev[i][j];

                    if (prev[i][a] != INT_MAX && prev[b][j] != INT_MAX && 
                        curr[i][j] > prev[i][a] + prev[b][j]) { // todo if graph not connected, check for edge absence
                        curr[i][j] = prev[i][a] + prev[b][j];
                        curr[j][i] = curr[i][j];
                    }
                    if (prev[i][b] != INT_MAX && prev[a][j] != INT_MAX && 
                        curr[i][j] > prev[i][b] + prev[a][j]) {
                        curr[i][j] = prev[i][b] + prev[a][j];
                        curr[j][i] = curr[i][j];
                    }
                }
            }
        }


        for (int i = 0; i < q; i++) {
            int a, b, k;
            cin >> a >> b >> k;
            a--; b--;

            int l = 1;
            int r = dp.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (dp[mid][a][b] < k)
                    r = mid;
                else
                    l = mid + 1;
            }

            cout << edges[changedIndex[l - 1]].w << ' ';
        }
        cout << '\n';
    }
}