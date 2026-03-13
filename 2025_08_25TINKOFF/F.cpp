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

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> eu(m), ev(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        eu[i] = u;
        ev[i] = v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    vector<bool> visited(n + 1, 0);
    vector<int> used(m, 0), parity(n + 1, 0);
    vector<int> parent(n + 1, -1), pedge(n + 1, -1), it(n + 1, 0);
    vector<int> from(m, 0), to(m, 0);

    for (int i = 1; i <= n; i++)
        if (!visited[i]) {
            vector<int> st;
            visited[i] = 1;
            it[i] = 0;
            parent[i] = -1;
            pedge[i] = -1;
            st.push_back(i);

            while (!st.empty()) {
                int u = st.back();

                if (it[u] < graph[u].size()) {
                    auto [v, id] = graph[u][it[u]++];

                    if (id == pedge[u]) continue;
                    
                    if (!visited[v]) {
                        visited[v] = 1;
                        parent[v] = u;
                        pedge[v] = id;
                        it[v] = 0;
                        st.push_back(v);
                    } else {
                        if (!used[id]) {
                            used[id] = 1;
                            from[id] = u;
                            to[id] = v;
                            parity[u] ^= 1;
                        }
                    }
                } else {
                    if (pedge[u] != -1 && !used[pedge[u]]) {
                        int id = pedge[u], p = parent[u];
                        if (parity[u]) {
                            from[id] = u;
                            to[id] = p;
                            parity[u] ^= 1;
                        } else {
                            from[id] = p;
                            to[id] = u;
                            parity[p] ^= 1;
                        }
                        used[id] = 1;
                    }
                    st.pop_back();
                }
            }
        }

    for (int i = 1; i <= n; i++) {
        if (parity[i]) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < m; i++)
        cout << from[i] << ' ' << to[i] << "\n";
}