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

struct Edge {ll b, w;};

ll dfs(vector<vector<Edge>> &links, int curr, int prev, ll dist, int target) {
    if (curr == target)
        return dist;
    
    for (Edge next : links[curr]) {
        if (next.b == prev)
            continue;

        ll result = dfs(links, next.b, curr, dist + next.w, target);
        if (result > 0)
            return result;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, s, t;
    cin >> n >> s >> t;

    vector<vector<Edge>> links (n);
    for (int i = 0; i < n - 1; i++) {
        ll a, b, w;
        cin >> a >> b >> w;

        links[a - 1].push_back({b - 1, w});
        links[b - 1].push_back({a - 1, w});
    }

    cout << dfs(links, s - 1, -1, 0, t - 1);
}