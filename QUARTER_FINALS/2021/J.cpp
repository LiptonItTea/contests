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

struct Game {
    int a, b, c, d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, k, x;
    cin >> n >> k >> x;

    set<ll> prev;
    set<ll> curr {x};

    for (int i = 0; i < n; i++) {
        prev.clear();
        prev.insert(curr.begin(), curr.end());
        curr.clear();

        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        for (auto it = prev.begin(); it != prev.end(); it++) {
            ll v = *it;

            if (v < x - k){
                if (c)
                    curr.insert(v + a);
                else
                    curr.insert(v - b);
            }
            if (v > x + k) {
                if (d)
                    curr.insert(v + a);
                else
                    curr.insert(v - b);
            }

            if (x - k <= v && v <= x + k) {
                if (c)
                    curr.insert(v + a);
                else
                    curr.insert(v - b);
                if (d)
                    curr.insert(v + a);
                else
                    curr.insert(v - b);
            }
        }
    }

    cout << *curr.rbegin();
}