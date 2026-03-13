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

    if (n < k) {
        cout << "NO\n";
        return 0;
    }

    int arifm = 1;
    for (int i = 2; i <= k; i++) {
        arifm += i;
    }

    if (n > arifm) {
        cout << "NO\n";
        return 0;
    }

    int currn = n;
    vector<vector<pair<int, int>>> pyramid (k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i && currn > (k - i); j++) {
            pyramid[i].push_back({j, j});
            currn--;
        }
        if (currn <= (k - i) && pyramid[i].size() < i + 1){
            pyramid[i].push_back({pyramid[i].size(), i});
            currn--;
        }
    }
    
    cout << "YES\n";
    // for (int i = 0; i < pyramid.size(); i++) {
    //     for (int j = 0; j < pyramid[i].size(); j++) {
    //         cout << pyramid[i][j].first << " " << pyramid[i][j].second << "\n";
    //     }
    // }
}