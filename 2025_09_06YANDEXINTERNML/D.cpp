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

// const double PI = acos(-1.0);
// const double EPS = 1e-12;

using namespace std;

struct Point { double x, y; };

bool fine(double m) {
    double theta0 = alpha[0];
    double L = -1e300, R = 1e300;
    for (int i = 0; i < n; ++i) {
        double r = normv[i];
        if (m > r + 1e-15) return false; // empty arc
        double ratio = (r == 0.0 ? 1.0 : m / r);
        if (ratio > 1.0) ratio = 1.0;
        if (ratio < -1.0) ratio = -1.0;
        double phi = acos(ratio); // in [0, pi]
        // unwrap center near theta0
        double k = round((theta0 - alpha[i]) / (2*PI));
        double c = alpha[i] + k * 2*PI;
        double li = c - phi;
        double ri = c + phi;
        if (li > ri) swap(li, ri);
        L = max(L, li);
        R = min(R, ri);
        if (L > R + 1e-18) return false; // early out
    }
    return L <= R + 1e-12;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cout << fixed << setprecision(9);
    
    int n1; 
    cin >> n1;

    vector<Point> A(n1);
    for (int i = 0; i < n1; i++) 
        cin >> A[i].x >> A[i].y;
    
    int n2; 
    cin >> n2;

    vector<Point> B(n2);
    for (int i = 0; i < n2; i++) 
        cin >> B[i].x >> B[i].y;
    
    Point p0; 
    cin >> p0.x >> p0.y;

    // Build s_i = y_i * (x_i - p0); y=+1 for class1, -1 for class2.
    vector<Point> S;
    S.reserve(n1 + n2);
    for (auto &q : A) {
        Point z{q.x - p0.x, q.y - p0.y};

        if (fabs(z.x) < 5e-16 && fabs(z.y) < 5e-16) {
            // A point exactly at p0 ⇒ impossible to separate strictly.
            cout << -1 << "\n";
            return 0;
        }

        S.push_back({z.x, z.y });
    }
    for (auto &q : B) {
        Point z{q.x - p0.x, q.y - p0.y};

        if (fabs(z.x) < 5e-16 && fabs(z.y) < 5e-16) {
            // A point exactly at p0 ⇒ impossible to separate strictly.
            cout << -1 << "\n";
            return 0;
        }
        
        S.push_back({-z.x, -z.y });
    };

    int n = S.size();
    vector<double> alpha(n), rad(n), normv(n);
    double hi = INT_MAX;
    for (int i = 0; i < n; ++i) {
        double r = hypot(S[i].x, S[i].y);
        normv[i] = r;
        alpha[i] = atan2(S[i].y, S[i].x);
        hi = min(hi, r);
    }

    auto feasible = [&](double m)->bool{
        
    };

    // Check basic separability with m = 0
    if (!feasible(0.0)) {
        cout.setf(std::ios::fixed); cout << setprecision(10) << -1 << "\n";
        return 0;
    }

    // Binary search maximal m
    double lo = 0.0;
    for (int it = 0; it < 70; ++it) {
        double mid = (lo + hi) * 0.5;
        if (feasible(mid)) lo = mid; else hi = mid;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(10) << lo << "\n";
    return 0;
}
