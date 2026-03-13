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

struct Entry {
    int a, b;

    double angle;
};

bool comp(const Entry &e1, const Entry &e2) {
    if (abs(e1.angle - e2.angle) > 1e-9)
        return e1.angle < e2.angle;

    return (e1.a + e1.b) < (e2.a + e2.b); // manhattan
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    double r;
    cin >> n >> r;

    vector<Entry> points;

    int li = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;

            points.push_back({a, b, 0});

            if (a < points[li].a)
                li = points.size() - 1;
            else if (a <= points[li].a && b < points[li].b)
                li = points.size() - 1;
        }
    }

    vector<Entry> check; check.reserve(points.size() - 1);
    for (int i = 0; i < points.size(); i++) {
        if (i == li)
            continue;
        check.push_back(points[i]);
    }

    for (int i = 0; i < check.size(); i++) {
        if (i == li)
            continue;
        
        int rx = points[i].a - points[li].a;
        int ry = points[i].b - points[li].b;
        check[i].angle = atan2(ry, rx);
    }
    sort(check.begin(), check.end(), comp);

    list<Entry> hull;
    hull.push_back(points[li]);
    hull.push_back(check[0]);
    hull.push_back(check[1]);
    auto curr_it = hull.begin();
    auto prev_it = hull.begin();
    advance(curr_it, 2);
    advance(prev_it, 1);
    for (int i = 2; i < check.size(); i++) {
        int ux = check[i].a - (*curr_it).a;
        int uy = check[i].b - (*curr_it).b;
        int vx = check[i].a - (*prev_it).a;
        int vy = check[i].b - (*prev_it).b;

        while (ux * vy - vx * uy < 0) {
            curr_it--;
            prev_it--;

            ux = check[i].a - (*curr_it).a;
            uy = check[i].b - (*curr_it).b;
            vx = check[i].a - (*prev_it).a;
            vy = check[i].b - (*prev_it).b;
        }

        hull.push_back(check[i]);
    }

    cout << "done";
}