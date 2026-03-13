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
    vector<ll> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int m;
    cin >> m;

    ll cur = INT_MIN;
    for (int i = 0; i < m; i++) {
        ll w, h;
        cin >> w >> h;

        ll bottom = max(cur, a[w - 1]);
        cout << bottom << "\n";
        
        cur = max(cur, bottom + h);
    }
}