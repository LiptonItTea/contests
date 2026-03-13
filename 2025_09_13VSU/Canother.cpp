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
    int maxa = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    int minm = m;
    for (int i = 0; i < n && minm > 0; i++) {
        int delta = min(maxa - a[i], minm);
        minm -= delta;
    }
    int minresult = maxa;

    if (minm > 0) {
        minresult += minm / n;
        if (minm % n != 0)
            minresult++;
    }

    cout << minresult << " " << maxa + m;
}