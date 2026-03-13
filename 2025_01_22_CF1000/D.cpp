#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll g(vector<ll>& prefa, vector<ll>& prefb, int x, int k) {
    ll result = 0;
    if (x > 0)
        result += prefa[x];
    if (x < k)
        result += prefb[k - x];

    return result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;

        vector<ll> a (n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        
        vector<ll> b (m, 0);
        for (int i = 0; i < m; i++) 
            cin >> b[i];
        sort(b.begin(), b.end());

        vector<ll> prefa (n / 2 + 1, 0);
        vector<ll> prefb (m / 2 + 1, 0);
        for (int i = 0; i < n / 2; i++)
            prefa[i + 1] = prefa[i] + a[n - 1 - i] - a[i];
        for (int i = 0; i < m / 2; i++)
            prefb[i + 1] = prefb[i] + b[m - 1 - i] - b[i];

        int kmax = max(0, min(n, min(m, (n + m) / 3)));
        cout << kmax << "\n";
        
        for (int k = 1; k <= kmax; k++) {
            int l = max(0, 2 * k - m);
            int r = min(k, n - k);
            while (r - l > 3) {
                int m1 = l + (r - l) / 3;
                int m2 = r - (r - l) / 3;

                ll guess1 = g(prefa, prefb, m1, k);
                ll guess2 = g(prefa, prefb, m2, k);
                
                if (guess1 < guess2)
                    l = m1;
                else if (guess1 > guess2)
                    r = m2;
                else
                    l = m1;
            }
            ll best = max(g(prefa, prefb, l, k), 
                        max(g(prefa, prefb, max(l, min(r, l + 1)), k), 
                        max(g(prefa, prefb, max(l, min(r, l + 2)), k), 
                            g(prefa, prefb, r, k))));
            cout << best << ' ';
        }

        cout << "\n";
    }

    return 0;
}