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

        cout << n * m << "\n";
    }
}