#include <iostream>

using namespace std;

int gcd (int a, int b) {
    if (a % b == 0)
        return b;
    if (b == 0)
        return a;
    
    return gcd(b, a % b);
}

int main() {
    for (int i = 0; i <= 16; i++) {
        cout << i << ": " << __lzcnt(i) << "\n";
    }
    // for (int i = 2; i < (1 << 25) + 1; i <<= 1) {
    //     int maxgcd = INT_MIN;

    //     for (int j = 1; j < i - 1; j++) {
    //         int curgcd = gcd(i - 1, j);

    //         maxgcd = max(maxgcd, curgcd);
    //     }

    //     cout << "{" << i - 1 << ", " << maxgcd << "}\n";
    // }
}