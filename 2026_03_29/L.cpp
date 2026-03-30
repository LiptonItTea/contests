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

struct Ell {
    ll x, y, r;
};

long double dist(ll x0, ll y0, ll x1, ll y1) {
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

long double dist_point_rect(long double x, long double y, long double x1, long double y1) {
    long double x_min = min(0.0l, x1);
    long double x_max = max(0.0l, x1);
    long double y_min = min(0.0l, y1);
    long double y_max = max(0.0l, y1);
    
    long double dx = max({0.0l, x_min - x, x - x_max});
    long double dy = max({0.0l, y_min - y, y - y_max});
    
    return hypot(dx, dy);
}

struct Edge {
    int i; long double w;
};

struct DEntry {
    int i; long double dist;
};

class DEntryComp {
public:
    bool operator()(const DEntry &d1, const DEntry &d2) const {
        if (d1.dist != d2.dist)
            return d1.dist < d2.dist;
        return d1.i < d2.i;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll x1, y1;
    cin >> x1 >> y1;

    ll x2, y2;
    cin >> x2 >> y2;

    if (x2 >= 0 && y2 >= 0 && x2 <= x1 && y2 <= y1) {
        cout << 0.0;
        return 0;
    }

    int n;
    cin >> n;

    vector<Ell> trees (n);
    for (int i = 0; i < n; i++)
        cin >> trees[i].x >> trees[i].y >> trees[i].r;

    vector<vector<Edge>> links (n + 2); // n - igor, n + 1 - stop
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long double l = max(0.0l, dist(trees[i].x, trees[i].y, trees[j].x, trees[j].y) - trees[i].r - trees[j].r);

            links[i].push_back({j, l});
            links[j].push_back({i, l});
        }
    }

    for (int i = 0; i < n; i++) { // igor
        long double l = max(0.0l, dist(trees[i].x, trees[i].y, x2, y2) - trees[i].r);

        links[i].push_back({n, l});
        links[n].push_back({i, l});
    }

    for (int i = 0; i < n; i++) { // stop
        ll x0 = trees[i].x, y0 = trees[i].y, r0 = trees[i].r;

        long double l = min(0.0l, dist_point_rect(x0, y0, x1, y1) - r0);

        links[i].push_back({n + 1, l});
        links[n + 1].push_back({i, l});
    }

    // igor - stop
    {
        ll x0 = x2, y0 = y2;
        long double l = dist_point_rect(x0, y0, x1, y1);

        links[n].push_back({n + 1, l});
        links[n + 1].push_back({n, l});
    }

    vector<DEntry> entries (n + 2);
    vector<bool> visited (n + 2);
    for (int i = 0; i < n; i++)
        entries[i] = {i, INT_MAX};
    entries[n] = {n, 0};
    entries[n + 1] = {n + 1, INT_MAX};

    set<DEntry, DEntryComp> q;
    for (int i = 0; i < n + 2; i++)
        q.insert(entries[i]);

    DEntry curr = *q.begin(); q.erase(q.begin());
    visited[curr.i] = true;
    while (curr.i != n + 1) {
        for (Edge next : links[curr.i]) {
            if (!visited[next.i] && entries[next.i].dist > entries[curr.i].dist + next.w) {
                q.erase(entries[next.i]);

                entries[next.i].dist = entries[curr.i].dist + next.w;
                q.insert(entries[next.i]);
            }
        }

        curr = *q.begin(); q.erase(q.begin());
        visited[curr.i] = true;
    }

    cout << curr.dist;
}