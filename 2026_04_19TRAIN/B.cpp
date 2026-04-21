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

    ll n, k;
    cin >> n >> k;

    if (k % 2 == 0) {
        ll result = n / (k / 2ll + 1ll);
        cout << result;
    }
    else {
        ll result = n / (k / 2ll + 1ll + k / 2ll + 1ll + 1ll) * 2;
        ll rest = n % (k / 2ll + 1ll + k / 2ll + 1ll + 1ll);
        if (rest >= k / 2 + 1 + 1)
            result++;

        cout << result;
    }
}