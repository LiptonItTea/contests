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

struct Artefact {
    int p, q;
};

bool sort_art(Artefact &a1, Artefact &a2) {
    return a1.p < a2.p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    int n, m;
    cin >> n >> m;

    vector<Artefact> as (n);
    for (int i = 0; i < n; i++)
        cin >> as[i].p >> as[i].q;

    vector<Artefact> bs (m);
    for (int i = 0; i < m; i++)
        cin >> bs[i].p >> bs[i].q;

    vector<ll> mincosta (1e4 + 1, INT_MAX);
    mincosta[0] = 0;
    sort(as.begin(), as.end(), sort_art);
    for (int i = 0; i < n; i++) {
        ll p = as[i].p, q = as[i].q;

        for (int j = 1e4; j >= 0; j--) {
            if (j - p < 0 || mincosta[j - p] == INT_MAX)
                continue;

            mincosta[j] = min(mincosta[j], mincosta[j - p] + q);
        }
    }

    vector<ll> mincostb (1e4 + 1, INT_MAX);
    mincostb[0] = 0;
    sort(bs.begin(), bs.end(), sort_art);
    for (int i = 0; i < m; i++) {
        ll p = bs[i].p, q = bs[i].q;

        for (int j = 1e4; j >= 0; j--) {
            if (j - p < 0 || mincostb[j - p] == INT_MAX)
                continue;

            mincostb[j] = min(mincostb[j], mincostb[j - p] + q);
        }
    }

    ll min_cost = INT_MAX;
    //solo
    for (ll i = max(0ll, c - a); i < mincosta.size(); i++) {
        if (mincosta[i] == INT_MAX)
            continue;

        min_cost = min(min_cost, mincosta[i]);
    }
    for (ll j = max(0ll, d - b); j < mincostb.size(); j++) {
        if (mincostb[j] == INT_MAX)
            continue;

        min_cost = min(min_cost, mincostb[j]);
    }

    // duo
    for (ll i = max(0ll, c - a - b); i < mincosta.size(); i++) {
        if (mincosta[i] == INT_MAX)
            continue;
        
        for (ll j = max(0ll, d - a - b); j < mincostb.size(); j++) {
            if (mincostb[j] == INT_MAX)
                continue;

            min_cost = min(min_cost, mincosta[i] + mincostb[j]);
        }
    }

    if (min_cost == INT_MAX) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << min_cost;
}