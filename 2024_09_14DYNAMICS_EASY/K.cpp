#include <iostream>

using namespace std;

int main() {
    freopen("joseph.in", "r", stdin);
    freopen("joseph.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;

    int res = 0;
    for (int i = 1; i <= n; i++){
        res = (res + k) % i;
    }

    cout << res + 1;
}