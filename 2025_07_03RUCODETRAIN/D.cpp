#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    // ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    
    int n;
    cin >> n;
    int amnt = 0;
    for (int _ = 0; _ < n; _++) {
        string p;
        cin >> p;

        amnt += 2;
        for (int i = p.size() - 1; i >= 0; i--) {
            if (p[i] == '0')
                amnt++;
            else if (p[i] == '9'){
                amnt--;
                break;
            }
            else
                break;
        }
    }

    cout << amnt << "\n";
}