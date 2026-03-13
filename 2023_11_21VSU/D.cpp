#include <iostream>
#include <iomanip>

using namespace std;

int fact(int n){
    int res = 1;
    for (int i = 2; i < n + 1; i++)
        res *= i;
    return res;
}

int main(){
    long long n, k, m;
    cin >> n >> k >> m;
    if(k == 0){
        cout << fixed << setprecision(8) << 0.0;
        return 0;
    }
    if(n <= m || n == k){
        cout << fixed << setprecision(8) << 1.0;
        return 0;
    }
    long long numerator = 1;
    for (int i = 0; i < k; i++){
        numerator *= (n - m - i);
    }
    long long denominator = 1;
    for (int i = 0; i < k; i++){
        denominator *= (n - i);
    }
    double result = ((double) numerator) / denominator;
    cout << fixed << setprecision(8) << 1 - result;
}