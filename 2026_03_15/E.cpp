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

ll one(ll n, ll eta) {
    ll k = n / eta;
    ll a = n % eta;

    ll result = a * (k + 1) + eta * (k + 1) * k / 2;
    return result;
}

ll two(ll n, ll eta) {
    ll result = 0;

    while (n > 0) {
        result += n / eta;
        if (n % eta != 0)
            result++;
        n--;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    for (int n = 1; n < 1e18; n++) {
        for (int eta = 1; eta < 1001; eta++) {
            if (one(n, eta) != two(n, eta)) {
                cout << "YOU ARE FUCKED UP XD " << n << " " << eta;
                return 0;
            }
        }
        cout << n << " ok\n";
    }
}