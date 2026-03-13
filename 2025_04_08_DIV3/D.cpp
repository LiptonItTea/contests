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
        int n;
        cin >> n;

        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            string type;
            cin >> type;

            if (type == "->") {
                ll x, y;
                cin >> x >> y;

                ll d = 0;

                ll curr_n = 1ll << (n - 1);
                while (curr_n >= 2) {
                    if (x < curr_n && y < curr_n) {
                        //do nothing
                    }
                    else if (x >= curr_n && y >= curr_n) {
                        d += curr_n;
                    }
                    else if (x >= curr_n && y < curr_n) {
                        d += curr_n * 2;
                    }
                    else {
                        d += curr_n * 3;
                    }
                    curr_n /= 2;
                }
            }
            else {
                ll d;
                cin >> d;

                ll x = 0,
                    y = 0;
                
                ll curr_n = 1ll << n;
                while (curr_n >= 1) {
                    if (d <= curr_n) {
                        // 0
                        //nothing
                    }
                    else if (d <= 2 * curr_n) {
                        // 1
                        x += curr_n / 2;
                        y += curr_n / 2;
                        d -= curr_n;
                    }
                    else if (d <= 3 * curr_n) {
                        // 2
                        x += curr_n / 2;
                        d -= curr_n * 2;
                    }
                    else {
                        // 3
                        y += curr_n / 2;
                        d -= curr_n * 3;
                    }
                    curr_n /= 4;
                }

                cout << x + 1 << " " << y + 1 << "\n";
            }
        }
    }
}