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

bool check(vector<ll> &vars, ll n, ll k, int x) {
    for (int i = 1; i < n; i++) {
        ll delta = 0;

        delta += vars[i - 1];
        if (i >= x)
            delta += vars[i - x];
        if ((i + 1) % 7 == 0)
            delta += vars[i / 7];

        vars[i] = delta;
    }

    if (vars[n - 1] == k)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll n, k;
    cin >> n >> k;

    if (n == 1 || n == 2) {
        cout << 0;
        return 0;
    }

    vector<ll> vars (n, 0);
    vars[0] = 1;

    int l = 2;
    int r = n;
    int x = r;
    while (r - l > 2) {
        x = (l + r) / 2;

        if (check(vars, n, k, x))
            break;
        
        if (vars[n - 1] < k)
            r = x;
        else
            l = x;
    }
    int best_answ = INT_MAX;

    if (check(vars, n, k, x))
        best_answ = min(best_answ, x);

    if (check(vars, n, k, l))
        best_answ = min(best_answ, l);

    if (r - 1 > 1 && check(vars, n, k, r - 1))
        best_answ = min(best_answ, r - 1);

    if (best_answ != INT_MAX)
        cout << best_answ;
    else
        cout << 0;
}