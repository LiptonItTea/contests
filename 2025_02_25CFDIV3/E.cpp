#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int k;
        cin >> k;

        int currX = 0;
        int currY = 0;
        int currK = k;
        vector<pair<int, int>> result;

        while (currK > 0) {
            double dn = (1.0 + sqrt(1 + 8.0 * currK)) / 2.0;
            int n = dn;

            for (int i = 0; i < n; i++) {
                result.push_back({currX, currY});
                currY++;
            }
            currX++;

            currK -= (n - 1) * n / 2;
        }

        cout << result.size() << "\n";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].first << " " << result[i].second << "\n";
        }
    }
}