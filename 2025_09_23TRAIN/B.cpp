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

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<int> a (n);
        a[0] = 1;
        a[n - 1] = 2;
        for (int i = 3; i <= n; i++)
            a[i - 2] = i;

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}