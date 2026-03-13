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

int bfs(vector<vector<int>>& links, vector<int>& dist, int start) {
    queue<int> q;
    q.push(start);
    q.push(-1);
    
    int smallest = INT_MAX;
    while (!q.empty()) {
        int current = q.front(); q.pop();
        int parent = q.front(); q.pop();
        
        for (int next : links[current]) {
            if (next == parent) {
                continue;
            }
            if (dist[next] != INT_MAX){
                smallest = min(smallest, dist[next] + dist[current] + 1);

                if (smallest == 3)
                    return 3;

                continue;
            }
            dist[next] = dist[current] + 1;
            q.push(next);
            q.push(current);
        }

        if (dist[current] * 2 + 1 >= smallest)
            break;
    }

    return smallest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> links (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        links[a - 1].push_back(b - 1);
        links[b - 1].push_back(a - 1);
    }

    int result = INT_MAX;
    vector<int> dists (n);
    for (int i = 0; i < n; i++) {
        fill(dists.begin(), dists.end(), INT_MAX);
        dists[i] = 0;
        
        int meow = bfs(links, dists, i);
        result = min(result, meow);
        if (result == 3)
            break;
    }

    if (result == INT_MAX)
        result = -1;
    cout << result << "\n";
}