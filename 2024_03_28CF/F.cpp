#include <iostream>

using namespace std;

int intlog2(int n) {
    int c = 1;
    int i = 0;
    while (c < n) {
        c <<= 1;
        i++;
    }
    if (c != n)
        i--;
    return i;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + 1 != c) {
            cout << "-1\n";
            continue;
        }

        if (a == 0) {
            if (b == 0)
                cout << 0 << "\n";
            else
                cout << b << "\n";
            continue;
        }

        int height = 0;
        int ha = intlog2(a);
        height += ha;
        int n_vaca = a + 1;
        int last_layera = (1 << (height + 1)) - 1 - a;

        int remb = max(0, b - last_layera);
        height += remb / n_vaca;
        height += (remb % n_vaca != 0) ? 1 : 0;
        
        if (remb % n_vaca == 0) {
            if (b == last_layera) {
                int remc = c;
                height += (remc != 0) ? 1 : 0;
    
                cout << height << "\n";
            }
            else {
                int remc = max(0, c - last_layera + b);
                height += (remc != 0) ? 1 : 0;

                cout << height << "\n";
            }

        }
        else {
            int remc = max(0, c - (n_vaca - remb % n_vaca));
            height += (remc != 0) ? 1 : 0;

            cout << height << "\n";
        }
        
    }
}