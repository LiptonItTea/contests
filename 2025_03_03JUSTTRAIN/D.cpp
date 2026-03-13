#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t, a, b;
    int n;
    cin >> t >> a >> b >> n;

    vector<ll> s (n, -1);
    for (int i = 0; i < n; i++) 
        cin >> s[i];
    
    ll rest = t % a;
    ll amount = t / a;

    vector<int> dp (rest + 1, 0);
    vector<set<int>> amounts (rest + 1, set<int> {});
    dp[0] = 1;
    amounts[0].insert(0);
    for (int i = 0; i < n; i++) {
        int w = s[i];
        for (int j = dp.size() - 1; j >= w; j--) {
            dp[j] = dp[j] | dp[j - w];
            
            for (auto it = amounts[j - w].begin(); it != amounts[j - w].end(); it++) {
                amounts[j].insert((*it) + 1);
            }
        }
    }

    // for (int i = 0; i < dp.size(); i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < amounts.size(); i++) {
    //     for (auto it = amounts[i].begin(); it != amounts[i].end(); it++){ 
    //         cout << *it << " ";
    //     }
    //     cout << "\n";
    // }

    for (ll i = rest + 1; i >= 1; i--) {
        if (dp[i] == 1) {
            ll restrest = rest - i;

            if (restrest % b != 0)
                continue;
            
            ll bamount = restrest / b;
            for (auto it = amounts[i].begin(); it != amounts[i].end(); it++) {
                int samount = *it;

                if (amount + samount < bamount - 1)
                    continue;
                
                //we fit
                cout << bamount;
                return 0;
            }
        }
    }

    //last chance konnor
    ll bamount = rest / b;
    if (rest % b == 0 && amount < bamount - 1){
        cout << bamount;
        return 0;
    }

    cout << -1;
}