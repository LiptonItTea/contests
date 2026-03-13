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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(6);

    int n;
    cin >> n;

    vector<ll> a (n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    vector<ll> pref (n + 1);
    for (int i = 1; i < n + 1; i++) {
        pref[i] = pref[i - 1] + (a[i - 1] - b[i - 1]) * (a[i - 1] - b[i - 1]);
    }

    int m;
    cin >> m;

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;

        cout << sqrt(pref[j] - pref[i - 1]) << "\n";
    }
}