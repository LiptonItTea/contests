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
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        vector<vector<int>> dpa (n + 1, vector<int> (26, 0));
        vector<vector<int>> dpb (n + 1, vector<int> (26, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                dpa[i + 1][j] = dpa[i][j];
                dpb[i + 1][j] = dpb[i][j];
            }

            dpa[i + 1][a[i] - 'a']++;
            dpb[i + 1][b[i] - 'a']++;
        }

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;

            int changes = 0;
            for (int j = 0; j < 26; j++) {
                changes += abs((dpa[r][j] - dpa[l - 1][j]) - (dpb[r][j] - dpb[l - 1][j]));
            }

            cout << changes / 2 << "\n";
        }
    }
}