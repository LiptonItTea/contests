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

    string s;
    cin >> s;

    int oneamount = 0;
    for (int i = 0; i < n; i++)
        oneamount += s[i] - '0';

    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<ll> possible;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0')
            possible.insert(a[i]);
        else if (i < n - 1 && s[i + 1])
            possible.insert(a[i]);
    }

    ll result = 0;
    int i = 0;
    for (auto it = possible.rbegin(); it != possible.rend() && i < oneamount; it++, i++) {
        result += *it;
    }

    cout << result;
}