#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>
#include <climits>
#include <math.h>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct point {
    double x, y, z;
};

double dist(double x, double y, double z, vector<point>& comps) {
    double result = 0;

    for (int i = 0; i < comps.size(); i++) {
        double ax = comps[i].x, ay = comps[i].y, az = comps[i].z;

        result += sqrt((x - ax) * (x - ax) + (y - ay) * (y - ay) + (z - az) * (z - az));
    }

    return result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    // ios_base::sync_with_stdio(false);
    cout << setprecision(2) << fixed;
    
    int n;
    cin >> n;

    vector<point> comps (n);
    for (int i = 0; i < n; i++)
        cin >> comps[i].x >> comps[i].y >> comps[i].z;

    vector<double> dx {-1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 1, -1, 0, 1};
    vector<double> dy {-1, -1, -1, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 1, 1, 1};
    vector<double> dz {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    
    double x = 49, y = 51, z = 50;
    double step = 100.0;
    double eps = 0.000001;
    double d = dist(x, y, z, comps);

    while (step > eps) {
        bool found = false;
        for (int i = 0; i < dx.size(); i++) { // check neighbour
            double ax = x + step * dx[i], ay = y + step * dy[i], az = z + step * dz[i];
            if (ax < 0 || ax > 100 || ay < 0 || ay > 100 || az < 0 || az > 100)
                continue;

            double checkd = dist(ax, ay, az, comps);
            if (checkd < d) {
                d = checkd;
                x = ax;
                y = ay;
                z = az;
                found = true;
                break;
            }
        }
        if (!found)
            step /= 1.25;
    }

    cout << x << " " << y << " " << z;
}