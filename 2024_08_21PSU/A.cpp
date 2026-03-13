#include <iostream>

using namespace std;

int main (){
    int n;
    cin >> n;

    int numerator = 2 * n * n * n + 18 * n * n + 46 * n + 30;
    int denominator = 2 * n * n + 16 * n + 30;

    cout << numerator / denominator;
}