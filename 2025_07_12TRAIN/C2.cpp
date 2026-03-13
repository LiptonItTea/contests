#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

struct Entry {
    int l, r, pos;
};

ll calculate_entry(Entry& e) {
    int l = e.l;
    int r = e.r;
    int pos = e.pos;

    ll res = 0;
    for (int c = 1; c <= r - l; c++) {
        res += min(r - 1 - c + 1, pos) - max(pos - c + 1, l) + 1;
    }
    return res;
}

ll count(string& s, vector<Entry>& episodes) {
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
            episodes.push_back({l, r - 1, pos});
            l = pos + 1;
            pos = r;
        }
        r++;
    }
    if (pos >= l) {
        for (int c = 1; c <= r - l; c++) {
            res += min(r - 1 - c + 1, pos) - max(pos - c + 1, l) + 1;
        }
        episodes.push_back({l, r - 1, pos});
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
        vector<Entry> episodes;
        ll best_res = count(s, episodes);

        int current_ep = 0;
        for (int i = 0; i < n; i++) {
            if (i > episodes[current_ep].pos)
                current_ep++;

            if (s[i] == '0') {
                ll curr_res = best_res;
                curr_res -= calculate_entry(episodes[current_ep - 1]) + calculate_entry(episodes[current_ep]);
                Entry nl = {episodes[current_ep - 1].l,
                            i - 1,
                            episodes[current_ep - 1].pos};
                Entry nr = {i + 1,
                            episodes[current_ep].r,
                            episodes[current_ep].pos};
                Entry nm = {episodes[current_ep - 1].pos + 1,
                            episodes[current_ep].pos - 1,
                            i};
                curr_res += calculate_entry(nl) + calculate_entry(nr) + calculate_entry(nm);

                if (curr_res > best_res) {
                    best_res = curr_res;
                    best_guess = i;
                }
            }
            else {
                
            }
        }

        if (best_guess == -1)
            cout << "-1\n";
        else
            cout << best_guess + 1 << "\n";
    }
}