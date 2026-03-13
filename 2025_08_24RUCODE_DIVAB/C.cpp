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

struct Entry {
    ll a, b;
};

int best_pos(ll x, vector<Entry> &vacs, int ignore) {
    ll best = LLONG_MIN;
    int res = -1;
    for (int i = 0; i < vacs.size(); i++) {
        if (i == ignore)
            continue;
        if (best < vacs[i].a * x + vacs[i].b) {
            best = vacs[i].a * x + vacs[i].b;
            res = i;
        }
    }

    return res;
}

int best_neg(ll x, vector<Entry> &vacs, int ignore) {
    ll best = LLONG_MAX;
    int res = -1;
    for (int i = 0; i < vacs.size(); i++) {
        if (i == ignore)
            continue;
        if (best > vacs[i].a * x + vacs[i].b) {
            best = vacs[i].a * x + vacs[i].b;
            res = i;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<Entry> vacs (n, {-1, -1});
    for (int i = 0; i < n; i++)
        cin >> vacs[i].a >> vacs[i].b;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;

        ll curr_best = LLONG_MIN;
        int first, second;

        // pos|pos
        first = best_pos(x, vacs, -1);
        second = best_pos(vacs[first].a * x + vacs[first].b, vacs, first);
        curr_best = max(curr_best, vacs[second].a * (vacs[first].a * x + vacs[first].b) + vacs[second].b);
        // pos|neg
        first = best_pos(x, vacs, -1);
        second = best_neg(vacs[first].a * x + vacs[first].b, vacs, first);
        curr_best = max(curr_best, vacs[second].a * (vacs[first].a * x + vacs[first].b) + vacs[second].b);
        // neg|pos
        first = best_neg(x, vacs, -1);
        second = best_pos(vacs[first].a * x + vacs[first].b, vacs, first);
        curr_best = max(curr_best, vacs[second].a * (vacs[first].a * x + vacs[first].b) + vacs[second].b);
        // neg|neg
        first = best_neg(x, vacs, -1);
        second = best_neg(vacs[first].a * x + vacs[first].b, vacs, first);
        curr_best = max(curr_best, vacs[second].a * (vacs[first].a * x + vacs[first].b) + vacs[second].b);

        cout << curr_best << "\n";
    }
}