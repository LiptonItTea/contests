#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>
#include <climits>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    // ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    
    int n, k;
    cin >> n >> k;

    vector<int> a (n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int l = 0;
    int r = 0;
    int currk = k;
    int bestlen = INT_MIN;
    while (r < n) {
        if (!a[r]) {
            if (currk > 0) {
                currk--;
            }
            else {
                while (a[l])
                    l++;
                l++;
            }
        }

        r++;
        bestlen = max(bestlen, r - l);
    }

    cout << bestlen;
}