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

int binfind(vector<ll> &pref, ll v) {
    int l = 0;
    int r = pref.size();

    while (r - l > 2) {
        int c = (l + r) / 2;

        if (c + 1 < pref.size() && pref[c] < v && v <= pref[c + 1])
            return c + 1;
        if (c - 1 >= 0 && pref[c - 1] < v && v <= pref[c])
            return c;

        if (pref[c] < v)
            l = c;
        else
            r = c;
    }
    
    if (v <= pref[l])
        return l;
    if (v <= pref[r - 1])
        return r - 1;
    return -1;
}

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<ll> a (n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<ll> pref (n, 0);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = a[i] + pref[i - 1];

    for (int i = 0; i < m; i++) {
        ll b;
        cin >> b;

        int ind = binfind(pref, b);
        ll actual = b;
        if (ind > 0)
            actual -= pref[ind - 1];
        cout << ind + 1 << " " << actual << "\n";
    }
}