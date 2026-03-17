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

ll mod = 1000000007;
vector<ll> values {1, 1, 2};
ll solve(ll n) {
    n--;
    while (n >= values.size()) {
        auto it = values.rbegin();
        ll a1 = *(it++);
        ll a2 = *(it++);
        ll a3 = *(it++);
        values.push_back((a1 + 2 * a2 + 3 * a3) % mod);
    }
    return values[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    for (int i = 1; i < 100; i++) {
        cout << i << " " << solve(i) << "\n";
    }
}