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

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<int> p (n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<int> seg (n);
        for (int i = 0; i < n; i++) {
            int value = p[i];

            seg[i] += 1;
            if (value > i + 1)
                seg[value - 1] += -1;
        }

        int pref = 0;
        int best = 0;
        for (int i = 0; i < n; i++) {
            pref = pref + seg[i];
            best = max(best, pref);
        }

        cout << best << "\n";
    }
}