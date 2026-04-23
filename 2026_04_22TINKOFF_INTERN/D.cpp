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

    int n;
    cin >> n;

    vector<ll> p (n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    ll fb = INT_MIN,
        fs = INT_MIN,
        sb = INT_MIN,
        ss = INT_MIN;

    for (int i = 0; i < n; i++) {
        fb = max(fb, -p[i]);
        fs = max(fs, fb + p[i]);
        sb = max(sb, fs - p[i]);
        ss = max(ss, sb + p[i]);
    }

    cout << ss;
}