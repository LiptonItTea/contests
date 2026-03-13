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

    vector<int> cats (n);
    for (int i = 0; i < n; i++)
        cin >> cats[i];

    int l = 0;
    int r = 0;
    map<int, int> curr;
    int best = INT_MIN;
    while (r < n) {
        if (curr.size() <= k) {
            curr[cats[r]]++;
            r++;
        }
        if (curr.size() > k) {
            while (curr.size() > k) {
                curr[cats[l]]--;
                if (curr[cats[l]] == 0)
                    curr.erase(cats[l]);
                l++;
            }
        }
        best = max(best, r - l);
    }

    cout << best;
}