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

    vector<pair<int, int>> data (n);
    int w = 0;
    for (int i = 0; i < n; i++){
        cin >> data[i].first >> data[i].second;
        w += (data[i].first - data[i].second) > 0;
    }

    if (2 * w > n) {
        cout << "0\n";
        return 0;
    }

    vector<bool> merged (n, false);
    int realn = n;
    int count = 0;
    // phase 1 remove L/D
    for (int i = 1; i < n; i++) {
        if (data[i].first - data[i].second > 0 || merged[i - 1])
            continue;

        if (data[i - 1].first - data[i - 1].second > 0 &&
            data[i - 1].first + data[i].first - data[i - 1].second - data[i].second <= 0)
            continue;

        merged[i] = true;
        count++;
        realn--;
        if (2 * w > realn) {
            cout << count << "\n";
            for (int i = 1; i < n; i++) 
                if (merged[i])
                    cout << i << " " << i + 1 << "\n";
            return 0;
        }
    }
    cout << -1;
}