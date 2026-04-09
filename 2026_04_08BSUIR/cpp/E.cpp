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

struct Point {
    int x, y;
};

bool comp_p(Point &p1, Point &p2) {
    if (p1.x != p2.x)
        return p1.x < p2.x;
    return p1.y < p2.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<Point> ps (n);
        for (int i = 0; i < n; i++)
            cin >> ps[i].x >> ps[i].y;

        sort(ps.begin(), ps.end(), comp_p);
        set<int> paths {ps[0].y};
        for (int i = 1; i < n; i++) {
            auto it = paths.upper_bound(ps[i].y);
            if (it != paths.begin() && it != paths.end() && *it > ps[i].y)
                it--;
            if (it == paths.end())
                it--;

            if (*it <= ps[i].y) {
                paths.erase(*it);
                paths.insert(ps[i].y);
            }
            else {
                paths.insert(ps[i].y);
            }
        }

        cout << paths.size() << "\n";
    }
}