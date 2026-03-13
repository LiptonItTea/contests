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

vector<vector<int>> links;
vector<int> colors;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    links.assign(n, vector<int> ());
    colors.assign(n, -1);
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--; v--;

        edges.insert({min(u, v), max(u, v)});
    }

    for (auto it = edges.begin(); it != edges.end(); it++) {
        links[it->first].push_back(it->second);
        links[it->second].push_back(it->first);
    }

    if (m == 0) {
        cout << -1;
        return 0;
    }

    colors[0] = 0;
    int checknext = -1;
    
    int count0 = 1, count1 = 0;
    for (int next : links[0]) {
        if (checknext == -1)
            checknext = next;

        if (colors[next] == 1){
            cout << -1;
            return 0;
        }

        colors[next] = 1;
        count1++;
    }

    for (int next : links[checknext]) {
        if (colors[next] != -1)
            continue;

        colors[next] = 0;
        count0++;
    }

    for (int c : colors) {
        if (c == -1) {
            cout << -1;
            return 0;
        }
    }

    if (count0 != count1) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int count = links[i].size();
        
        for (int next : links[i]) {
            if (colors[next] == colors[i]) {
                cout << -1;
                return 0;
            }
        }

        if (colors[i] == 0 && count != count1) {
            cout << -1;
            return 0;
        }
        if (colors[i] == 1 && count != count0) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == colors[0])
            cout << i + 1 << " ";
    }
}