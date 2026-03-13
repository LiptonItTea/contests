#include <iostream>
#include <vector>
#include <iomanip>

#define ll long long

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;

    int n, q;
    cin >> n >> q;

    vector<ll> pref (n + 1, 0);
    vector<ll> pref2 (n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        ll x;
        cin >> x;
        pref[i] = x + pref[i - 1];

        pref2[i] = x * x + pref2[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int code;
        cin >> code;

        if (code == 1) { // get
            int k;
            cin >> k;
            
            double mean = (pref[n] - pref[n - k]) / (double) k;
            double enumerator = (pref2[n] - pref2[n - k]) / (double) k - 2 * mean / (double) k * (pref[n] - pref[n - k]) + mean * mean;
            cout << enumerator << "\n";
        }
        else { // add
            ll x;
            cin >> x;

            pref.push_back(pref[n] + x);
            pref2.push_back(pref2[n] + x * x);
            n++;
        }
    }
}