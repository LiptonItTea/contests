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

struct FenTree {
    vector<int> t;
    int size;

    FenTree (int n) {
        size = n;
        t.assign(size, 0);
    }

    void inc (int i, int delta) {
        for (; i < size; i = i | (i + 1))
            t[i] += delta;
    }

    int sum (int i) {
        int sum = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            sum += t[i];
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<int> a (n);
    vector<int> compress (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        compress[i] = a[i];
    }
    sort(compress.begin(), compress.end());
    map<int, int> comp_map;
    for (int i = 0; i < n; i++)
        comp_map[compress[i]] = i;

    vector<int> a_comp; a_comp.reserve(n);
    for (int i = 0; i < n; i++) {
        int to_insert = comp_map[a[i]];
        if (i > 0) {
            if (a_comp[i - 1] != to_insert)
                a_comp.push_back(to_insert);
        }
        else
            a_comp.push_back(to_insert);
    }
    n = a_comp.size();

    FenTree ft (n + 1);
    int result = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        result = max(result, ft.sum(a_comp[i]));
        ft.inc(a_comp[i] + 1, 1);
    }

    cout << result;
}