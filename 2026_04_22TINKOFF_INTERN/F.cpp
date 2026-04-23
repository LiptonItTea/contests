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
    ll x, y;
};

bool comp_en(Entry &e1, Entry &e2) {
    return (e1.x - e1.y) > (e2.x - e2.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll a, b, n;
    cin >> a >> b >> n;

    vector<Entry> apps (n);
    for (int i = 0; i < n; i++)
        cin >> apps[i].x >> apps[i].y;

    sort(apps.begin(), apps.end(), comp_en);

    multiset<ll> best;
    ll currsum = 0;
    vector<ll> xpref (n);
    for (int i = 0; i < n; i++) {
        best.insert(apps[i].x);
        currsum += apps[i].x;

        if (best.size() > a){
            auto it = best.begin();
            currsum -= *it;
            best.erase(it);
        }

        xpref[i] = currsum;
    }

    best.clear();
    currsum = 0;
    vector<ll> ysuff (n);
    for (int i = n - 1; i >= 0; i--) {
        best.insert(apps[i].y);
        currsum += apps[i].y;

        if (best.size() > b) {
            auto it = best.begin();
            currsum -= *it;
            best.erase(it);
        }

        ysuff[i] = currsum;
    }

    ll result = max(xpref[0], ysuff[n - 1]);
    for (int i = 0; i < n - 1; i++)
        result = max(result, xpref[i] + ysuff[i + 1]);

    cout << result;
}