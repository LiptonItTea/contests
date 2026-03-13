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

    int x, y, k;
    cin >> x >> y >> k;

    if (y <= x) {
        cout << max(x, y);
        return 0;
    }
    
    int result = y;
    result += max(0, y - x - k);
    cout << result;
}