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

struct Game {
    ll size, rating;
};

bool comp(const Game &g1, const Game &g2) {
    return g1.size < g2.size;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        ll n, k, x, m;
        cin >> n >> k >> x >> m;

        vector<Game> games (n);
        for (int i = 0; i < n; i++)
            cin >> games[i].size;
        for (int i = 0; i < n; i++)
            cin >> games[i].rating;
        
        sort(games.begin(), games.end(), comp);

        ll l = 0;
        ll r = LLONG_MAX - 1;
        
        ll c;
        while (r - l > 2) {
            c = (l + r) / 2;

            int good = x;
            ll size = 0;
            int rest = k - x;
            ll rest_size = 0;
            int i = 0;
            while (i < n) {
                if (good > 0 && games[i].rating >= c) {
                    good--;
                    size += games[i].size;
                    i++;
                    continue;
                }
                if (rest > 0) {
                    rest--;
                    rest_size += games[i].size;
                    i++;
                    continue;
                }
                i++;
            }
            
            if (good > 0 || size > m || rest_size > m) { // what to do if size + rest_size > m ???
                r = c;
                continue;
            }
            l = c;
        }

        int good = x;
        ll size = 0;
        int rest = k - x;
        ll rest_size = 0;
        int i = 0;
        while (i < n) {
            if (good > 0 && games[i].rating >= l) {
                good--;
                size += games[i].size;
                i++;
                continue;
            }
            if (rest > 0) {
                rest--;
                rest_size += games[i].size;
                i++;
                continue;
            }
            i++;
        }

        if (good == 0 && rest == 0 && size + rest_size <= m) {
            cout << l << "\n";
            continue;
        }

        good = x;
        size = 0;
        rest = k - x;
        rest_size = 0;
        i = 0;
        while (i < n) {
            if (good > 0 && games[i].rating >= r - 1) {
                good--;
                size += games[i].size;
                i++;
                continue;
            }
            if (rest > 0) {
                rest--;
                rest_size += games[i].size;
                i++;
                continue;
            }
            i++;
        }

        cout << "-1\n";
    }
}