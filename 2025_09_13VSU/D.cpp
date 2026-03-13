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

        vector<int> w (n);
        for (int i = 0; i < n; i++)
            cin >> w[i];
        sort(w.begin(), w.end());

        int result = 0;
        for (int s = 1; s < 101; s++) {
            int curr = 0;

            int l = 0;
            int r = n - 1;

            while (l < r && w[r] >= s)
                r--;

            while (l < r) {
                if (w[l] + w[r] > s) {
                    r--;
                    continue;
                }

                if (w[l] + w[r] == s) {
                    curr++;
                    l++;
                    r--;
                    continue;
                }

                if (w[l] + w[r] < s) {
                    l++;
                    continue;
                }
            }

            result = max(result, curr);
        }

        cout << result << "\n";
    }
}