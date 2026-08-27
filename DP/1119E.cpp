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

    vector<ll> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll result = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        result += a[i] / 3;
        a[i] %= 3;

        j = max(j, i + 1);
        while (j < n && a[i] > 0) {
            if (a[j] < 2){
                j++;
                continue;
            }
            
            ll delta = min(a[i], a[j] / 2);
            result += delta;
            a[i] -= delta;
            a[j] -= delta * 2;
        }
    }

    cout << result;
}