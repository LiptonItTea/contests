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

    int n, k;
    cin >> n >> k;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, ll> counts {{a[0], 1}};
    map<int, ll> dp2 {{a[0], 0}};
    map<int, ll> dp3 {{a[0], 0}};
    for (int i = 1; i < n; i++) {
        if (a[i] % k == 0 && counts.find(a[i] / k) != counts.end()) {
            dp3[a[i]] += dp2[a[i] / k];
            dp2[a[i]] += counts[a[i] / k];
        }

        counts[a[i]]++;
    }

    ll result = 0;
    for (auto it = dp3.begin(); it != dp3.end(); it++)
        result += it->second;

    cout << result;

    // vector<ll> dp2 (n, 0);
    // vector<ll> dp3 (n, 0);
    // map<int, vector<int>> found {{a[0], {0}}};
    // for (int i = 1; i < n; i++) {
    //     if (a[i] % k == 0 && found.find(a[i] / k) != found.end()) {
    //         auto it = found.find(a[i] / k);
            
    //         for (int index : it->second) {
    //             dp2[i] += 1;
    //             dp3[i] += dp2[index];
    //         }
    //     }
    //     found[a[i]].push_back(i);
    // }

    // ll result = 0;
    // for (int i = 0; i < n; i++)
    //     result += dp3[i];

    // cout << result;
}