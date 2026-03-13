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

int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<int> a (n);
    map<int, int> amounts;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        amounts[a[i]]++;
    }

    ll result = 1;
    for (auto it = amounts.begin(); it != amounts.end(); it++){ 
        result = (result * (it->second + 1)) % mod;
    }
    cout << result - 1;
}