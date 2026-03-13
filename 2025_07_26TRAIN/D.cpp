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

int check(vector<ll> &b, ll delta) {
    int best_res = INT_MAX;

    for (ll start = b[0] - 1; start <= b[0] + 1; start++) {
        ll prev = start;
        int result = 0;

        bool bad = false;
        for (int i = 1; i < b.size(); i++) {
            if (abs(prev + delta - b[i]) >= 2){
                bad = true;
                break;
            }

            if (prev + delta - b[i] != 0)
                result++;
            prev += delta;
        }

        if (bad)
            continue;
        
        best_res = min(best_res, result);
    }

    if (best_res == INT_MAX)
        return -1;
    return best_res;
}

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<ll> b(n);
    ll maxv = INT_MIN;
    int maxp = -1;
    ll minv = INT_MAX;
    int minp = -1;
    for (int i = 0; i < n; i++){
        cin >> b[i];

        if (maxv < b[i]) {
            maxv = b[i];
            maxp = i;
        }
        if (minv > b[i]) {
            minv = b[i];
            minp = i;
        }
    }

    if (maxp == minp) {
        cout << 0;
        return 0;
    }
    
    int best_res = INT_MAX;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int dist = maxp - minp;
            if ((maxv + j - (minv + i)) % dist != 0)
                continue;
            
            int result = check(b, (maxv + j - (minv + i)) / dist);
            if (result < 0)
                continue;
            
            if (i != 0)
                result++;
            if (j != 0)
                result++;
            best_res = min(best_res, result);
        }
    }

    if (best_res == INT_MAX)
        cout << -1;
    else
        cout << best_res;
}