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

    int result = 0;
    for (int i = 0; i < n; i++) {
        int lowest = max(a[i] - a[0], a[0] - a[i]);
        int biggest = a[i] + a[0];

        int l = lower_bound(a.begin(), a.end(), lowest) - a.begin();
        int r = lower_bound(a.begin(), a.end(), biggest) - a.begin();
        for (int j = 0; j < i; j++) {
            lowest = max(a[i] - a[0], a[0] - a[i]);
            biggest = a[i] + a[0];

            while (l > 0 && a[l - 1] >= lowest)
                l--;
            while (r < n - 1 && a[r + 1] <= biggest)
                r++;
            
            result += r - l + 1;
        }
    }
}