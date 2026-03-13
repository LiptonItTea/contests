#include <iostream>
#include <math.h>

using namespace std;

int main (){
    int t;
    cin >> t;

    for (int z = 0; z < t; z++){
        int l, r;
        cin >> l >> r;

        int kmax = 0;
        for (int j = l; j <= r; j*=2){
            kmax++;
        }

        long amount = 0;
        amount += ((int) (r / pow(2, kmax - 1))) - l + 1;
        amount += max(0, (((int) (r / 3 / pow(2, kmax - 2))) - l + 1) * (kmax - 1));

        // cout << "2: " << ((int) (r / pow(2, kmax - 1))) - l + 1 << "\n";
        // cout << "3: " << ((int) (r / 3 / pow(2, kmax - 2))) - l + 1 << "\n";
        // cout << "3 swap: " << (((int) (r / 3 / pow(2, kmax - 2))) - l + 1) * (kmax - 1) << "\n";
        cout << kmax << " " << (amount % 998244353) << "\n";
    }
}