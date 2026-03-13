#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
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
    int x, y, z, w;
};

class EntryLess {
    public:
        bool operator()(const Entry &e1, const Entry &e2) const {
            if (e1.x != e2.x)
                return e1.x < e2.x;
            if (e1.y != e2.y)
                return e1.y < e2.y;
            if (e1.z != e2.z)
                return e1.z < e2.z;
            
            return e1.w < e2.w;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int k, l, m, n;
    cin >> k >> l >> m >> n;

    int amount;
    cin >> amount;
    set<Entry, EntryLess> seen;
    for (int i = 0; i < n; i++) {
        int x, y, z, w;
        cin >> x >> y >> z >> w;

        seen.insert({x, y, z, w});
    }

    int result = 0;
    for (auto it = seen.begin(); it != seen.end(); it++) {
        int x = it->x, y = it->y, z = it->z, w = it->w;

        for (int u = -1; u < 2; u++) {
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    for (int h = -1; h < 2; h++) {
                        if (k < x + i || x + i <= 0 || l < y + j || y + j <= 0 || m < z + h || z + h <= 0 || n < w + u || w + u <= 0)
                            continue;
                        if (seen.find({x + i, y + j, z + h, w + u}) != seen.end())
                            // print(x + i, y + j, z + h, w + u)
                            continue;
                        result++;
                    }
                }
            }
        }
    }

    cout << result;
}