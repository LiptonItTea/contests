#include <iostream>

using namespace std;

long long f(long long x, long long a){
    return x / a + x % a;
}

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        long long l, r, a;
        cin >> l >> r >> a;

        long long maxX = f(r, a);
        long long curX = f(max(l, r - r % a - 1), a);
        
        cout << max(maxX, curX) << "\n";
    }
}