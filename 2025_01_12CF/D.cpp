#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, k, l;
        cin >> n >> k >> l;

        vector<int> a (n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        vector<int> b (n, 0);
        b[0] = 0;
        int t = 2 * a[0];
        for (int i = 1; i < n; i++) {
            int afterFactor = 2 * a[i] - t + b[i - 1] / 2 + 2 * k;
            int middleFactor = b[i - 1] + 4 * k;
            int preFactor = 4 * a[i] + 2 * t;

            b[i] = min(4 * l, min(preFactor, max(middleFactor, afterFactor)));
            t += max(0, b[i] - b[i - 1] - 4 * k) / 2;
        }

        t += max(0, 4 * l - b[n - 1] - 4 * k) / 2;

        cout << t << "\n";
    }
}