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

    int n, k;
    cin >> n >> k;

    vector<string> s (2);
    for (int i = 1; i >= 0; i--)
        cin >> s[i];

    ll best = LLONG_MAX;
    int bestFloor = -1;
    int bestPos = -1;
    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < n; j++) {
            ll curr = INT_MIN;
            
            for (ll l = 0; l < n; l++)
                if (s[i][l] - '0')
                    curr = max(curr, abs(j - l));
            for (ll l = 0; l < n; l++)
                if (s[1 - i][l] - '0')
                    curr = max(curr, (j + 1) + (l + 1) + k);

            if (curr < best) {
                best = curr;
                bestFloor = i;
                bestPos = j;
            }
        }
    }

    cout << best << "\n" << bestFloor + 1 << " " << bestPos + 1;
}