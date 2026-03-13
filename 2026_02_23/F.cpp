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

    ll n, q;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        ll a;
        cin >> a;
        
        if (a == 0) {
            cout << 0 << "\n";
            continue;
        }

        if (a % 2 == 0) {
            cout << -1 << "\n";
            continue;
        }

        ll count = 0;
        while (abs(a) > 0){
            a /= 2;
            count++;
        }
        
        cout << count << "\n";
    }
}