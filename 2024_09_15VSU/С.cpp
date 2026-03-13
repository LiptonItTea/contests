#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int k;
        cin >> k;

        int d0, d1;
        cin >> d1 >> d0;

        if(d1 == 1 && d0 == 0){
            cout << "YES\n";
            cout << "1 " << k - 1 << "\n";
            cout << "1 " << 1 << "\n";
            continue;
        }

        if(d1 <= d0){
            cout << "YES\n";
            cout << "2 " << d1 << " " << d1 << "\n";
            cout << "1 " << d0 - d1 << "\n";
            continue;
        }

        if(d1 > d0 + 1){
            cout << "YES\n";
            cout << "2 " << d1 - 1 << " " << d1 - 1 << "\n";
            cout << "1 " << k + d0 - d1 + 1 << "\n";
            continue;
        }

        cout << "NO\n";
    }
}