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

struct DSU {
    vector<int> p;
    vector<int> size;

    DSU(int n) {
        p.assign(n + 1, 0);
        size.assign(n + 1, 1);

        for (int i = 0; i < n + 1; i++)
            p[i] = i;
    }

    int get(int u) {
        return u == p[u] ? u : p[u] = get(p[u]);
    }

    bool unite(int u, int v) {
        u = get(u);
        v = get(v);

        if (u == v)
            return false;

        if (size[u] < size[v])
            swap(u, v);
        
        p[v] = u;
        size[u] += size[v];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, q;
    cin >> n >> q;

    vector<DSU> dsu {DSU(0)};
    for (int k = 1; k <= 9; k++)
        dsu.push_back(DSU(n));

    ll answer = 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        answer += c;

        for (int k = c; k <= 9; k++)
            dsu[k].unite(a, b);
    }

    for (int i = 0; i < q; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        for (int k = w; k <= 9; k++)
            if (dsu[k].unite(u, v))
                answer--;

        cout << answer << '\n';
    }
}