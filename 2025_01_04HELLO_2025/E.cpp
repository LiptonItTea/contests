#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct Entry {
    int a, b, w;
};

bool compareEntries(Entry& e1, Entry& e2) {
    return e1.w < e2.w;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<vector<ll>> weights (n, vector<ll> (m, INT_MAX));
        for (int i = 0; i < n; i++)
            weights[i][i] = 0;
        vector<Entry> allw (m);
        for (int i = 0; i < m; i++) {
            int v, u, w;
            cin >> v >> u >> w;

            weights[v - 1][u - 1] = w;
            weights[u - 1][v - 1] = w;
            
            allw[i].a = v - 1;
            allw[i].b = u - 1;
            allw[i].w = w - 1;
        }
        sort(allw.begin(), allw.end(), compareEntries);

        vector<vector<ll>> d (n, vector<ll> (m, INT_MAX));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (weights[i][j] != INT_MAX)
                    d[i][j] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                }
            }
        }

        vector<Entry> queries (q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i].a >> queries[i].b >> queries[i].k;
        }
    
        for (int i = 0; i < q; i++) {
            int a = queries[i].a - 1;
            int b = queries[i].b - 1;
            int k = queries[i].k - 1;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][j] > d[i][a] + d[b][j] || d[i][j] > d[i][b] + d[a][j]) {

                    }
                }
            }
        }
    }
}