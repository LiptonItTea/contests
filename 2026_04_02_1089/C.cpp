#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<int> a (n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b (n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int result = 0;
        // first
        if (a[0] - gcd(a[0], a[1]) > 0)
            result++;
        // last
        if (a[n - 1] - gcd(a[n - 2], a[n - 1])  )
            result++;
        // between
        for (int i = 1; i < n - 1; i++) {
            ll g12 = gcd(a[i - 1], a[i]);
            ll g23 = gcd(a[i], a[i + 1]);

            ll g13 = gcd(g12, g23);

            ll lcm = g12 * g23 / g13;
            
            if (lcm != a[i] && lcm < b[i] || lcm + g12 != a[i] && lcm + g12 < b[i] || lcm + g23 != a[i] && lcm + g23 < b[i])
                result++;
        }

        cout << result << "\n";
    }
}