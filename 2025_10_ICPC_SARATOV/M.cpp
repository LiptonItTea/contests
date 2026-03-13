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
        int n;
        cin >> n;

        string s;
        cin >> s;

        int result = 0;
        int multi = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                result++;

            if (i != 0 && s[i - 1] == '1' && s[i] == '1')
                multi = max(multi, 1);
            if (i != 0 && i != n - 1 && s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '1')
                multi = max(multi, 2);
        }

        cout << result - multi << "\n";
    }
}