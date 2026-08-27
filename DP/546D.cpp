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

    int maxn = 5000000 + 1;
    vector<int> sieve (maxn, 0);
    for (int i = 2; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) {
            if (sieve[j] == 0)
                sieve[j] = i;
        }
    }

    vector<int> counts (maxn, 0);
    for (int i = 2; i < maxn; i++) {
        int curr = i;
        while (sieve[curr] > 0) {
            counts[i]++;
            curr /= sieve[curr];
        }
    }

    vector<int> pref (maxn, 0);
    for (int i = 1; i < maxn; i++)
        pref[i] = pref[i - 1] + counts[i];

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        cout << pref[a] - pref[b] << "\n";
    }
}