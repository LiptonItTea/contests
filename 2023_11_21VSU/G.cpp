#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    long long lenA2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
    long long lenB2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    long long lenC2 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);

    long long det = abs(x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x1 * y3 - x2 * y1);

    double r = sqrt(lenA2) * sqrt(lenB2) * sqrt(lenC2) / (2 * det);
    cout << fixed << r;
}