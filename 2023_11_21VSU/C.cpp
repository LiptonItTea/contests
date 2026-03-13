#include <iostream>

using namespace std;

int main(){
    long long n, k, m;
    cin >> n >> k >> m;

    //m
    //m + n - 1
    //n * (m + m + n - 1) / 2
    long long am = min(n, k);
    long long sum = am * (2 * m + am - 1) / 2;
    cout << sum;
    // long long sum = 0;
    // for (int i = 0; i < min(n, k); i++)
    //     sum += m + i;
    // cout << sum;
}