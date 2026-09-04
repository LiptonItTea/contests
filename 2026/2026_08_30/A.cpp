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

void add(vector<ll>& source, vector<ll>& v) {
    for (int i = 0; i < 26; i++)
        source[i] += v[i];
}

void sub(vector<ll>& source, vector<ll>& v) {
    for (int i = 0; i < 26; i++)
        source[i] -= v[i];
}

void mult(vector<ll>& source, int v) {
    for (int i = 0; i < 26; i++)
        source[i] *= v;
}

void count(string& s, vector<ll>& v) {
    for (int i = 0; i < s.size(); i++)
        v[s[i] - 'A']++;
}

bool positive(vector<ll> &v) {
    for (int i = 0; i < 26; i++)
        if (v[i] < 0)
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> counts (n, vector<ll> (26));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        count(s, counts[i]);
    }

    vector<ll> request (26);
    for (int i = 0; i < n; i++)
        add(request, counts[i]);

    vector<ll> order (request.begin(), request.end());
    mult(order, m);

    for (int i = 0; i < n; i++) {
        vector<ll> remaining (order.begin(), order.end());
        vector<ll> delta (counts[i].begin(), counts[i].end());
        mult(delta, m);
        sub(remaining, delta);

        int l = 0;
        int r = 1e9;
        while (r - l > 1) {
            int k = (l + r) / 2;

            vector<ll> rest (remaining.begin(), remaining.end());
            vector<ll> main_pack(request.begin(), request.end());
            sub(main_pack, counts[i]);
            mult(main_pack, k);
            sub(rest, main_pack);
            sub(rest, counts[i]);

            if (positive(rest))
                l = k;
            else
                r = k;
        }

        vector<ll> rest (remaining.begin(), remaining.end());
        vector<ll> main_pack(request.begin(), request.end());
        sub(main_pack, counts[i]);
        mult(main_pack, l);
        sub(rest, main_pack);
        sub(rest, counts[i]);

        if (positive(rest))
            cout << l << " ";
        else
            cout << -1 << " ";
    }
}