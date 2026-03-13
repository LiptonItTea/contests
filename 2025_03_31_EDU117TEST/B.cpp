#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        ll n, k, x;
        cin >> n >> k >> x;

        vector<ll> a (n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        vector<ll> suf (n, 0);
        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + a[i];
        
        ll blockPos = x / suf[0];
        ll intra = x % suf[0];
        if (blockPos - (intra == 0 ? 1 : 0) > k - 1) {
            cout << "0\n";
            continue;
        }
        if (intra == 0) {
            blockPos--;

            cout << n * (k - 1 - blockPos) + 1 << "\n";
            continue;
        }
        ll inner = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (suf[i] >= intra) {
                inner = i + 1;
                break;
            }
        }

        if (inner != -1) {
            cout << n * (k - 1 - blockPos) + inner << "\n";
        }
        else{
            cout << "0\n";
        }
    }
}