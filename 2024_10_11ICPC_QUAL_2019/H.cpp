#include <iostream>

using namespace std;

long long modu = 1000000007;

long long fastPowModulo(long long num, long long pow){
    if(pow == 0)
        return 1;
    
    if(pow % 2 == 0){
        long long result = fastPowModulo(num, pow / 2);
        return (result * result) % modu;
    }
    return (num * fastPowModulo(num, pow - 1)) % modu;
}

long long inverseModu(long long n){
    return fastPowModulo(n, modu - 2);
}

long long f(long long n){
    long long result = 21;
    if(n % 2 == 0)
        result *= -1;
    
    result = (result + (5ll * fastPowModulo(3ll, n)) % modu) % modu;
    result = (result - (4ll * n) % modu) % modu;
    if(result < 0)
        result += modu;
    result = (result - 16ll) % modu;
    if(result < 0)
        result += modu;
    result = (result * inverseModu(16ll)) % modu;

    if(n % 2 == 0)
        result = (result + 1ll) % modu;
    return result;
}

long long f2(long long n){
    long long fn2 = 1;
    long long fn1 = 1;
    long long fn = 1;
    for (long long i = 3; i <= n; i++){
        fn = (((2ll * fn1) % modu + (3ll * fn2) % modu) % modu + i) % modu;
        fn2 = fn1;
        fn1 = fn;
    }
    return fn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    if(n == 1 || n == 2){
        cout << 1;
        return 0;
    }

    cout << f(n);
    // cout << f(31195) << " " << f2(31195);
    // for (int i = 1; i < n; i++){
        
    //     cout << i << " ";
    //     if(f(i) == f2(i))
    //         cout << "YES\n";
    //     else{
    //         cout << "NO\n";
    //         return 0;
    //     }
    // }
}