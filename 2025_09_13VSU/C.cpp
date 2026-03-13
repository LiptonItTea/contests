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

bool check(vector<int> &a, int n, int c, int currm) {
    for (int i = 0; i < n && currm > 0; i++){ 
        int delta = min(c - a[i], currm);
        currm -= delta;
    }
    return currm == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 1;
    int r = 101;
    int c;
    while (r - l > 2) {
        c = (l + r) / 2;

        bool result = check(a, n, c, m);
        if (result)
            r = c + 1;
        else
            l = c;
    }
    c = (l + r) / 2;

    int minresult = INT_MAX;
    if (check(a, n, l, m))
        minresult = min(minresult, l);
    if (r != l && check(a, n, r - 1, m))
        minresult = min(minresult, r - 1);
    if (check(a, n, c, m))
        minresult = min(minresult, c);

    cout << minresult;

    int maxresult = INT_MIN;
    for (int i = 0; i < n; i++)
        maxresult = max(maxresult, a[i]);

    cout << " " << maxresult + m;
}