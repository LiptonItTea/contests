#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct Point {
    ll x, y;
};

ll det(ll a11, ll a12, ll a21, ll a22) {
    return a11 * a22 - a12 * a21;
}

ll area2(Point p1, Point p2, Point p3) {
    return abs(det(p3.x - p1.x, p2.x - p1.x, p3.y - p1.y, p2.y - p1.y));
}

int main() {
    int n;
    cin >> n;

    vector<Point> points (n, {-1, -1});
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points[i].x = x;
        points[i].y = y;
    }

    ll fullArea = 0;
    for (int i = 2; i < n; i++) {
        fullArea += area2(points[0], points[i - 1], points[i]);
    }

    int l = 0,
        r = 2;
    ll curLeftArea = 0;
    ll areasDelta = LLONG_MAX;
    int minl = -1;
    int minr = -1;
    while (l < n) {
        while (true) {
            ll delta = area2(points[l % n], points[(r - 1) % n], points[r % n]);
            // if (curLeftArea + delta > fullArea - curLeftArea - delta) {
            //     break;
            // }
            // curLeftArea += delta;
            if (areasDelta > abs(curLeftArea + delta - (fullArea - curLeftArea - delta))) {
                areasDelta = abs(curLeftArea + delta - (fullArea - curLeftArea - delta));
                curLeftArea += delta;
                minl = l;
                minr = r;
                r++;
                continue;
            }
            break;
        }
        curLeftArea -= area2(points[l % n], points[(l + 1) % n], points[(l + 2) % n]);
        l++;
        if (areasDelta > abs(curLeftArea - (fullArea - curLeftArea))) {
            areasDelta = abs(curLeftArea - (fullArea - curLeftArea));
            minl = l;
            minr = r;
        }
    }

    cout << minl + 1 << " " << minr + 1;
}