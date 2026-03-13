#include <iostream>

using namespace std;

long long fact(long long n, long long m){
    long long res = 1;
    for (long long i = 0; i < n; i++){
        res = (res * (i + 1)) % m;
    }
    return res;
}

long long fastPow(long long num, long long pow, long long m){
    if(pow == 0){
        return 1;
    }
    if(pow % 2 == 0){
        long long prevNum = fastPow(num, pow / 2, m);
        // cout << (prevNum * prevNum) % m << "\n";
        return (prevNum * prevNum) % m;
    }
    else{
        return (fastPow(num, pow - 1, m) * num) % m;
    }
}

long long mo = 1000000007;

int main(){
    //find inverse for 2 by module
    long long div = fastPow(2, mo - 2, mo);
    
    long long t;
    cin >> t;

    for (long long _ = 0; _ < t; _++){
        long long n;
        cin >> n;

        long long f = fact(2 * n, mo);
        
        // cout << "   Divisor: " << div << "\n";
        cout << "" << (f * div) % mo << "\n";
    }
}