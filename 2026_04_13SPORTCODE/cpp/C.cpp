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

void dfs(int curr, vector<vector<int>> &links, vector<bool> &visited, vector<vector<bool>> &visitedEdge, set<pair<int, int>> &result) {
    visited[curr] = true;

    for (int i = 0 ; i < links[curr].size(); i++) {
        int next = links[curr][i];

        if (visited[next]) {
            if (!visitedEdge[curr][i]) {
                // cout << next + 1 << " " << curr + 1 << "\n";
                result.insert({next + 1, curr + 1});
                visitedEdge[curr][i] = true;

                for (int j = 0; j < visitedEdge[next].size(); j++) {
                    if (links[next][j] == curr && !visitedEdge[next][j]) {
                        visitedEdge[next][j] = true;
                        break;
                    }
                }
            }
            continue;
        }

        // cout << curr + 1 << " " << next + 1 << "\n";
        result.insert({curr + 1, next + 1});
        visitedEdge[curr][i] = true;
        for (int j = 0; j < visitedEdge[next].size(); j++) {
            if (links[next][j] == curr && !visitedEdge[next][j]) {
                visitedEdge[next][j] = true;
                break;
            }
        }
        dfs(next, links, visited, visitedEdge, result);
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> links (n);
    vector<vector<bool>> visitedEdge (n);
    vector<pair<int, int>> order (m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        links[a - 1].push_back(b - 1);
        links[b - 1].push_back(a - 1);
        visitedEdge[a - 1].push_back(false);
        visitedEdge[b - 1].push_back(false);
        order[i] = {a, b};
    }

    vector<bool> visited (n, false);
    set<pair<int, int>> result;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, links, visited, visitedEdge, result);
        }
    }

    for (pair<int, int> p : order) {
        if (result.find({p.first, p.second}) != result.end())
            cout << p.first << " " << p.second << "\n";
        else
            cout << p.second << " " << p.first << "\n";
    }
}