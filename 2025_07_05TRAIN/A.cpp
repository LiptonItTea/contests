#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    // ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    
    int n, s, l;
    cin >> n >> s >> l;

    vector<int> a (n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int amount = 0;
    int curmin = INT_MAX;
    int curmax = INT_MIN;
    int prevr = 0;
    for (int i = 0; i < n; i++) {
        curmin = min(curmin, a[i]);
        curmax = max(curmax, a[i]);

        if (curmax - curmin > s) {
            if (i - prevr < l) {
                cout << -1;
                return 0;
            }
            prevr = i;
            amount++;
            curmin = a[i];
            curmax = a[i];
        }
    }
    amount++;

    cout << amount;
}