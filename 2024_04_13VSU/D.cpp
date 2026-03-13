#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int* pots = new int[n];
    for (int i = 0; i < n; i++){
        cin >> pots[i];
    }

    sort(pots, pots + n);
    double l = pots[0];
    double r = pots[n - 1];
    double z;
    while (l < r){
        z = (r + l) / 2;
        // cout << l << " " << z << " " << r << "\n";

        double rest = 0;
        for (int i = n - 1; i >= 0; i--){
            if(pots[i] < z)
                break;
            
            rest += pots[i] - z;
        }

        double needed = 0;
        for (int i = 0; i < n; i++){
            if(pots[i] > z)
                break;
            
            needed += z - pots[i];
        }

        double neededK = 100.0 / (100.0 - k) * needed;

        // cout << "rest      " << rest << "\n";
        // cout << "needed    " << needed << "\n";
        // cout << "neededK " << neededK << "\n";
        if(abs(neededK - rest) < 1e-6){
            cout << z;
            break;
        }
        else if(neededK > rest){
            r = z;
        }
        else {
            l = z;
        }
    }
}