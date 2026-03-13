#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

ll count(string& s) {
    int n = s.size();

    ll res = 0;

    int l = 0;
    int r = 0;
    int pos = -1;
    while (r < n) {
        if (s[r] == '1') {
            if (pos < l) {
                pos = r++;
                continue;
            }

            for (int c = 1; c <= r - l; c++) {
                res += min(r - 1 - c + 1, pos) - max(pos - c + 1, l) + 1;
            }
            l = pos + 1;
            pos = r;
        }
        r++;
    }
    if (pos >= l) {
        for (int c = 1; c <= r - l; c++) {
            res += min(r - 1 - c + 1, pos) - max(pos - c + 1, l) + 1;
        }
    }

    return res;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int best_guess = -1;
        ll best_res = count(s);

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';

            ll curr_res = count(s);
            if (curr_res > best_res) {
                best_res = curr_res;
                best_guess = i;
            }

            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }

        if (best_guess == -1)
            cout << "-1\n";
        else
            cout << best_guess + 1 << "\n";
    }
}