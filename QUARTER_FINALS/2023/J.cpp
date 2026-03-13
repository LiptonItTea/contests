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

struct Entry {
    int l, r, i;
};

class EntryLess {
    public:
        bool operator()(const Entry &e1, const Entry &e2) const {
            return e1.r > e2.r;
        }
};

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

        vector<int> p (n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<vector<Entry>> entries (2 * n - 1);
        for (int i = 0; i < n - 1; i++) {
            Entry e;
            e.l = min(p[i], p[i + 1]);
            e.r = max(p[i], p[i + 1]);
            e.i = i;

            entries[e.l].push_back(e);
        }

        priority_queue<Entry, vector<Entry>, EntryLess> prior;
        vector<int> result (n - 1);
        for (int i = 1; i < 2 * n - 1; i++) {
            if (i % 2 == 1) {
                for (auto it = entries[i].begin(); it != entries[i].end(); it++)
                    prior.push(*it);
            }
            else {
                Entry best = prior.top();
                prior.pop();

                result[best.i] = i;
            }
        }

        for (int i = 0; i < n - 1; i++)
            cout << result[i] << " ";
        cout << "\n";
    }
}