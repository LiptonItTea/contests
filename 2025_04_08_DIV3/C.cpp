#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int x, k;
        cin >> x >> k;

        if (x == 1) {
            if (k == 2)
                cout << "YES\n";
            else 
                cout << "NO\n";
            continue;
        }

        if (k > 1) {
            cout << "NO\n";
            continue;
        }

        bool found = false;
        for (int y = 2; y * y <= x; y++) {
            if (x % y == 0) {
                found = true;
                // cout << y << "\n";
                break;
            }
        }

        if (found) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}