#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    freopen("angle2.in", "r", stdin);
    freopen("angle2.out", "w", stdout);
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long long len1sq = x1 * x1 + y1 * y1;
    long long len2sq = x2 * x2 + y2 * y2;

    double cos = (x1 * x2 + y1 * y2) / sqrt(len1sq * len2sq);
    double angle = acos(cos);

    cout << fixed << setprecision(15) << angle;
}