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

const double eps = 1e-6;

double manhattan(vector<double> &p1, vector<double> &p2) {
    double res = 0;

    for (int i = 0; i < p1.size(); i++)
        res += abs(p1[i] - p2[i]);

    return res;
}

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<double> p1 (3);
    for (int i = 0; i < 3; i++)
        cin >> p1[i];

    vector<double> p2 (3);
    for (int i = 0; i < 3; i++)
        cin >> p2[i];

    // check if belong to 1 plane
    bool one_plane = false;
    for (int i = 0; i < 3; i++) {
        if (abs(p1[i]) < eps && abs(p2[i]) < eps || 
            abs(p1[i] - n) < eps && abs(p2[i] - n) < eps) {
                one_plane = true;
                break;
        }
    }

    if (one_plane) {
        double d = manhattan(p1, p2);
        cout << d;
        return 0;
    }

    // check if belong to near planes
    bool near_planes = true;
    for (int i = 0; i < 3; i++) {
        if (abs(p1[i]) < eps && abs(p2[i] - n) < eps || 
            abs(p1[i] - n) < eps && abs(p2[i]) < eps) {
                near_planes = false;
                break;
        }
    }

    if (near_planes) {
        double d = manhattan(p1, p2);
        cout << d + 1;
        return 0;
    }

    // opposite planes
    // move point to edges and test again
    double best = INT_MAX;
    for (int i = 0; i < 3; i++) {
        if (abs(p1[i]) < eps && abs(p2[i] - n) < eps || 
            abs(p1[i] - n) < eps && abs(p2[i]) < eps) {

            for (int j = 0; j <= n; j += n) {
                vector<double> g1 (3);
                vector<double> g2 (3);

                bool first = true;
                for (int k = 0; k < 3; k++) {
                    if (k == i) {
                        g1[k] = p1[k];
                        g2[k] = p1[k];

                        if (abs(p1[k]) < eps) {
                            g1[k] += 0.5;
                            g2[k] += 0.5;
                        }
                        else {
                            g1[k] -= 0.5;
                            g2[k] -= 0.5;
                        }
                        continue;
                    }

                    if (first) {
                        g1[k] = abs(j - n);
                        g2[k] = p1[k];
                        first = false;
                        continue;
                    }
                    g1[k] = p1[k];
                    g2[k] = j;
                    
                }
        

                best = min(best, manhattan(g1, p2));
                best = min(best, manhattan(g2, p2));
            }

            break;
        }
    }

    cout << best + 2;
}