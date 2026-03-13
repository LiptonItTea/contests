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

    int n;
    cin >> n;

    vector<int> a (2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int result = 0;
    for (int i = 1; i < n; i++) {
        result += a[i] - a[i - 1];
        result += a[i + n] - a[i + n - 1];
    }

    cout << result << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << a[i + n] << "\n";
    }
}