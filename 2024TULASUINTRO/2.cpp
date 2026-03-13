#include <iostream>

using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    double newX = x * (100 - z) / 100.0;

    double amount = y / newX;
    cout << (long long) amount;
}