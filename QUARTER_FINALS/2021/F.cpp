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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        ll a, b, x;
        cin >> a >> b >> x;

        if (a < b)
            swap(a, b);

        if (x > a) {
            cout << "NO\n";
            continue;
        }

        while (!(a % b == x)) {
            if (a == x || b == x)
                break;

            if (x <= a && (a - x) % b == 0)
                break;
            
            a = a % b;
            if (a < b)
                swap(a, b);

            if (b == 0)
                break;
        }

        if (a == x || b == x) {
            cout << "YES\n";
            continue;
        }

        if (b != 0 && (a % b == x || (a - x) % b == 0)) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}