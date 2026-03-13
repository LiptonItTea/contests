#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

double collideX (int r, double a1, double a2){
    double x = (cos(a2) - cos(a1)) / sin(a1 - a2) * r;
    return x;
}

double collideY (int r, double a1, double a2){
    double y = (sin(a1) - sin(a2)) / sin(a1 - a2) * r;
    return y;
}

int main(){
    int n, r;
    cin >> n >> r;

    cout << fixed << setprecision(16);

    double* angles = new double[n];

    for (int i = 0; i < n; i++){
        double a = M_PI * 2 / n * i;
        angles[i] = a;
    }

    for (int i = n - 1; i >= 1; i--){
        double a1 = angles[i - 1];
        double a2 = angles[i];

        cout << collideX(r, a1, a2) << " " << collideY(r, a1, a2) << "\n";
    }
    double a1 = angles[n - 1];
    double a2 = angles[0];
    cout << collideX(r, a1, a2) << " " << collideY(r, a1, a2);
}