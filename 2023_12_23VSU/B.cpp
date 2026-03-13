#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long result = 0;
    for (long long i = 0; i < n; i++){
        long long delta = pow(2, i + 1);
        result += delta;
    }

    cout << result;
}