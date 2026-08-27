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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, x; // meow
    cin >> n >> x;

    vector<int> c (n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> pref (n);
    for (int i = 0; i < n; i++)
        pref[i] = c[i] * (n - i);

    sort(pref.begin(), pref.end());

    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr + pref[i] > x) {
            cout << i;
            return 0;
        }
        curr += pref[i];
    }
    cout << n;
}