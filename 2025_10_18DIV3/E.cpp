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
        ll n, k, l, r;
        cin >> n >> k >> l >> r;

        vector<int> a (n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        map<int, ll> k_1;
        map<int, ll> kex;
        ll result = 0;
        ll x = 0, y = 0;
        for (ll i = 0; i < n; i++) {
            while (x < n && (k_1.size() < k - 1 || k_1.size() == k - 1 && k_1.find(a[x]) != k_1.end()))
                k_1[a[x++]]++;
            while (y < n && (kex.size() < k || kex.size() == k && kex.find(a[y]) != kex.end()))
                kex[a[y++]]++;

            if (kex.size() != k)
                break;

            result += min(i + r, y) - max(i + l - 1, x);
            k_1[a[i]]--;
            if (k_1[a[i]] == 0)
                k_1.erase(a[i]);
            kex[a[i]]--;
            if (kex[a[i]] == 0)
                kex.erase(a[i]);
        }

        cout << result << '\n';
    }
}