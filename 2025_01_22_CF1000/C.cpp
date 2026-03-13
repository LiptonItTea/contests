#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
set<int> amounts;
map<int, int> lasts;
void dfs(int curr, int prev) {
    visited[curr] = true;
    amounts.insert(nodes[curr].size());
    lasts[nodes[curr].size()] = curr;

    for (int link : nodes[curr]) {
        if (link == prev) {
            continue;
        }

        dfs(link, curr);
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

        nodes.clear();
        nodes.assign(n, vector<int> ());
        visited.clear();
        visited.assign(n, false);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;

            nodes[u - 1].push_back(v - 1);
            nodes[v - 1].push_back(u - 1);
        }

        amounts.clear();
        lasts.clear();
        dfs(0, -1);

        int result = 1;
        result += *amounts.rbegin() - 1;
        int removed = lasts.rbegin()->second;

        for (int i = 0; i < n; i++) {
            if (i == removed)
                continue;
            
            for (auto it = nodes[i].begin(); it != nodes[i].end(); it++) {
                if (*it == removed) {
                    nodes[i].erase(it);
                    break;
                }
            }
        }

        vector<set<int>> comps;
        visited.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (i == removed)
                continue;
            if (visited[i])
                continue;

            amounts.clear();
            dfs(i, -1);
            comps.push_back(amounts);
        }
        
        int best_amnt = 0;
        int best_index = -1;

        for (int i = 0; i < comps.size(); i++) {
            if (*comps[i].rbegin() > best_amnt) {
                best_amnt = *comps[i].rbegin();
                best_index = i;
            }
        }

        result += best_amnt - 1;
        

        cout << max(0, result) << "\n";
    }
}