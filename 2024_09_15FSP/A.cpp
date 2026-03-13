#include <iostream>

using namespace std;

long long modulo = 1000003;

long long factModulo(long long n){
    long long result = 1;
    for (long long i = 1; i <= n; i++){
        result = (result * i) % modulo;
    }

    return result;
}

int main() {
    long long n;
    cin >> n;

    if(n > modulo){
        cout << 0;
        return 0;
    }

    cout << factModulo(n);
}