#include <iostream>
#include <math.h>

using namespace std;

long long modulo = 1000000007;

long long gcd(long long a, long long b){
    if(a < b){
        long long temp = a;
        a = b;
        b = temp;
    }
    if(b == 0)
        return a;
    
    return gcd(b, a % b);
}

long long fastPowModulo(long long num, long long pow){
    if(pow == 0){
        return 1;
    }

    if(pow % 2 == 0){
        long long res = fastPowModulo(num, pow / 2);
        return (res * res) % modulo;
    }
    return (num * fastPowModulo(num, pow - 1)) % modulo;
}

long long inverseModulo(long long num){
    return fastPowModulo(num, modulo - 2);
}

int main(){
    long long k, n;
    cin >> k >> n;

    //считаем неподвижные точки
    long long ig = 0;
    //к смещений
    for (int i = 0; i < k; i++){
        //циклов
        long long cycles = gcd(k, i);
        //покрасок циклов
        long long variantsOfPaint = fastPowModulo(n, cycles);

        ig = (ig + variantsOfPaint) % modulo;
    }

    //делим на кол-во смещений
    ig = (ig * inverseModulo(k)) % modulo;

    cout << ig;
}