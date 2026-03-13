#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll n;
    cin >> n;

    set<ll> good {1};
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i % 2 == 0)
                good.insert(i / 2);
            if ((n / i) % 2 == 0)
                good.insert(n / i / 2);
        }
    }

    cout << good.size() << "\n";
    for (auto it = good.begin(); it != good.end(); it++)
        cout << *it << " ";
}