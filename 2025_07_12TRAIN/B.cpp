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
    
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        ll n, m;
        cin >> n >> m;
        n -= 1;
        m -= 1;
        n /= 3;
        m /= 3;
        ll amount = n * 3 + m * 3 + 1;

        amount += (n * m) * 4;
        amount -= m + 1 + n;
        if (n * m <= 0)
            cout << "0\n";
        else
            cout << amount << "\n";
    }
}