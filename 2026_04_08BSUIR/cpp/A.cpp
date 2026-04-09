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
        string s;
        cin >> s;
        int n = s.size();

        vector<ll> prefa (n + 1);
        ll result = 0;
        for (int i = 0; i < n; i++) {
            prefa[i + 1] = prefa[i];
            if (s[i] == 'a')
                prefa[i + 1]++;

            if (s[i] == 'i')
                result += prefa[i + 1];
        }

        cout << result << "\n";
    }
}