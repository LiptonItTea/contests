#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++){
        long long a, b, n, m;
        cin >> a >> b >> n >> m;

        long long q, r;
        if(a * m <= b * (m + 1)){
            q = n / (m + 1);
            r = n % (m + 1);
        }
        else{
            q = 0;
            r = n;
        }

        cout << q * min(a * m, b * (m + 1)) + r * min(a, b) << "\n";
    }
}