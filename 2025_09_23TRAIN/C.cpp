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

    string s;
    cin >> s;

    bool inv = false;
    for (int i = 0; i < k; i++) {
        if (s[i] != s[n - 1 - i])
            inv = !inv;
    }

    string sub = s.substr(k, n - 2 * k);
    if (inv) {
        for (int i = sub.size() - 1; i >= 0; i--)
            cout << sub[i];
        return 0;
    }
    cout << sub;
}