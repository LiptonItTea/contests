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

int dfs(int curr, int prev, vector<vector<int>> &links, vector<bool> &colored, vector<int> &c, vector<int> &parent) {
    parent[curr] = prev;
    for (int next : links[curr]) {
        if (next == prev)
            continue;
        
        c[curr] += dfs(next, curr, links, colored, c, parent);
    }

    if (colored[curr])
        c[curr] += 1;

    return c[curr];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, k;
    cin >> n >> k;

    vector<bool> colored (n, 0);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;

        colored[c - 1] = true;
    }

    vector<vector<int>> links (n, vector<int> ());
    vector<int> parent (n, -1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        links[v - 1].push_back(u - 1);
        links[u - 1].push_back(v - 1);
    }

    vector<int> c (n, 0);
    dfs(0, -1, links, colored, c, parent);

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (colored[i])
            continue;
        
        bool good = true;

        for (int next : links[i]) {
            if (next == parent[i])
                continue;
            
            if (c[next] == 0) {
                good = false;
                break;
            }
        }

        if (i != 0 && c[0] - c[i] == 0)
            good = false;
        

        if (good)
            result.push_back(i);
    }

    cout << result.size() << "\n";
    for (int i : result)
        cout << i + 1 << " ";
}