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

    int best = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0)
            continue;

        int x = k * i + n / i;
        if (x / k == i){
            best = min(best, x);
        }

        x = k * (n / i) + i;
        if (x / k == (n / i)){
            best = min(best, x);
        }
    }

    cout << best;
}