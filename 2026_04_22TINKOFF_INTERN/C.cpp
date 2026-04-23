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

ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll n, m;
    cin >> n >> m;

    ll result = (m * (m - 1)) % mod;
    for (int i = 1; i < n; i++)
        result = (result * ((m - 1 + (((m - 2) * (m - 2)) % mod)) % mod)) % mod;
    
    if (result < 0)
        result += mod;
    
    cout << result;
}