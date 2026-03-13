#include <iostream>
#include <vector>

using namespace std;

struct FenTree {
    vector<long long> t;
    int size;

    FenTree (vector<long long>& source) {
        size = source.size();
        t.assign(size, 0);

        for (int i = 0; i < size; i++)
            inc(i, source[i]);
    }

    void inc (int i, long long delta) {
        for (; i < size; i = i | (i + 1))
            t[i] += delta;
    }

    long long sum (int i) {
        long long sum = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            sum += t[i];
        return sum;
    }
};

int main() {
    freopen("rsq.in", "r", stdin);
    freopen("rsq.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<long long> a (n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    FenTree ft (a);
    for (int i = 0; i < m; i++) {
        long long t, x, y;
        cin >> t >> x >> y;

        if (t == 0) {
            cout << ft.sum(y - 1) - ft.sum(x - 2) << "\n";
        }
        else {
            long long currElement = ft.sum(x - 1) - ft.sum(x - 2);
            ft.inc(x - 1, y - currElement);
        }
    }
}