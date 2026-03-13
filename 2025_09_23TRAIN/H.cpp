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

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> segs (n);
    for (int i = 0; i < n; i++)
        cin >> segs[i].first >> segs[i].second;

    sort(segs.begin(), segs.end());

    int start = -1;
    int end = -1;
    int maxr = 1;
    for (int i = 0; i < n; i++) {
        if (maxr < segs[i].first) {
            if (start == -1)
                start = maxr;
            end = segs[i].first;
        }
        maxr = max(maxr, segs[i].second + 1);
    }
    if (maxr < m + 1){
        if (start == -1)
            start = maxr;
        end = m + 1;
    }

    cout << end - start;
}