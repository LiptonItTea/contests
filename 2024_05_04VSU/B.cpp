#define _USE_MATH_DEFINES

#include <fstream>
#include <math.h>
#include <iomanip>
#include <iostream>

using namespace std;

int main(){
    int ix1, iy1, ix2, iy2;
    freopen("angle2.in", "r", stdin);
    cin >> ix1 >> iy1 >> ix2 >> iy2;

    double x1 = (double) ix1;
    double y1 = (double) iy1;
    double x2 = (double) ix2;
    double y2 = (double) iy2;

    // double a = atan2(iy1, ix1);
    // double b = atan2(iy2, ix2);

    // double angle = abs(b - a);
    // if(angle > M_PI)
    //     angle = M_2_PI - angle;

    double len1 = sqrt(x1 * x1 + y1 * y1);
    double len2 = sqrt(x2 * x2 + y2 * y2);

    double angle = acos((x1 * x2 + y1 * y2)/(len1 * len2));
    
    freopen("angle2.out", "w", stdout);
    cout << fixed << setprecision(12);
    cout << angle;
}