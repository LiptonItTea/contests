#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool found = false;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                //prefix
                int tolerance = 1;
                bool good = true;
                for (int j = 0; j < n / i; j++) {
                    for (int k = 0; k < i; k++) {
                        if (s[j * i + k] != s[k])
                            tolerance--;
                        
                        if (tolerance < 0){
                            good = false;
                            break;
                        }
                    }
                    if (!good)
                        break;
                }
                if(good){
                    cout << i << "\n";
                    found = true;
                    break;
                }

                //suffix
                //prefix
                tolerance = 1;
                good = true;
                for (int j = n / i - 1; j >= 0; j--) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (s[j * i + k] != s[n - i + k])
                            tolerance--;
                        
                        if (tolerance < 0){
                            good = false;
                            break;
                        }
                    }
                    if (!good)
                        break;
                }
                if(good){
                    cout << i << "\n";
                    found = true;
                    break;
                }
            }
        }
        if (!found)
            cout << n << "\n";
    }
}