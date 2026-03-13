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

    vector<int> l (n), r(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i] >> a[i];
    
    vector<int> dpleft (n, 0);
    for (int i = 1; i < n; i++)
        dpleft[i] = min(l[i], dpleft[i - 1] + a[i - 1]);
    
    vector<int> dpright (n, 0);
    for (int i = n - 2; i >= 0; i--)
        dpright[i] = min(r[i], dpright[i + 1] + a[i + 1]);

    int best = 0;
    for (int i = 0; i < n; i++)
        best = max(best, a[i] + dpleft[i] + dpright[i]);
    
    cout << best;
}