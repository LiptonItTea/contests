#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    freopen("angle1.in", "r", stdin);
    freopen("angle1.out", "w", stdout);
    int x, y;
    cin >> x >> y;

    double result = atan2(y, x);
    if(result < 0){
        result += 2 * M_PI;
    }
    cout << fixed << setprecision(15) << result;
}