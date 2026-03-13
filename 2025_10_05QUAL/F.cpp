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
        int x, y, z, k;
        cin >> x >> y >> z >> k;

        int l = 0;
        int r = (x + y + z) / 3 + 2;
        while (r - l > 2) {
            int c = (l + r) / 2;

            
        }
    }
}