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
    ll x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<Entry> points (n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<Entry> controls (n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> controls[i].x >> controls[i].y;

    double miny = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        double x0 = points[i].x, y0 = points[i].y;
        double x1 = controls[i].x - x0, y1 = controls[i].y - y0;
        double x2 = points[i + 1].x - x0, y2 = points[i + 1].y - y0;
        int b = y0;
        x0 = 0; y0 = 0;

        double det = (x0 * x0 * x1 + x1 * x1 * x2 + x2 * x2 * x0 -
                    (x2 * x2 * x1 + x0 * x0 * x2 + x1 * x1 * x0));

        double A = (double) ((x1 - x2) * y0 + (x2 - x0) * y1 + (x0 - x1) * y2) / det;
        double B = (double) ((x2 * x2 - x1 * x1) * y0 + (x0 * x0 - x2 * x2) * y1 + (x1 * x1 - x0 * x0) * y2) / det;
        double C = (double) ((x1 * x1 * x2 - x2 * x2 * x1) * y0 + (x2 * x2 * x0 - x0 * x0 * x2) * y1 + (x0 * x0 * x1 - x1 * x1 * x0) * y2) / det;
        C += b;

        if ((x1 - x2) * y0 + (x2 - x0) * y1 + (x0 - x1) * y2 == 0 || A <= 0) {
            miny = min(miny, (double) min(y0, y2));
            continue;
        }
        
        cout << A << " " << B << " " << C << "\n";
        double x = -B / 2 / A;
        double y = A * x * x + B * x + C;

        miny = min(miny, y);
    }
    
    if (miny >= 0)
        cout << miny;
    else
        cout << 0;
}