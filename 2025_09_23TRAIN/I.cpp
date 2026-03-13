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

int test(int n, int k, int f, vector<int>& a, int c) {
    int currk = k;
    int prev = 0;
    int i = 0;
    while (i < n) { // find first
        if (a[i] - prev > c) {
            currk--;
            prev = a[i - 1];
            break;
        }
        i++;
    }

    while (i < n) {
        if (a[i] - prev > 2 * c) {
            currk--;
            prev = a[i - 1];
        }
        if (currk < 0)
            break;
        i++;
    }
    if (f - prev > c) {
        currk--;
    }

    return currk;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int k, n, f;
    cin >> n >> k >> f;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int maxd = 0;
    for (int i = 1; i < n; i++)
        maxd = max(maxd, (a[i] - a[i - 1]) / 2 + (a[i] - a[i - 1]) % 2);

    int l = max(a[0] - 0, max(f - a[n - 1], maxd));
    int r = f + 1;

    while (r - l > 2) {
        int c = (l + r) / 2;

        int currk = test(n, k, f, a, c);

        if (currk < 0) // failed
            l = c;
        else
            r = c + 1;
    }

    if (test(n, k, f, a, l) >= 0) {
        cout << l;
        return 0;
    }
    
    cout << l + 1;
}