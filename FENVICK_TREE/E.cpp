#include <iostream>
#include <vector>

using namespace std;

struct FenTree {
    vector<long long> t;
    int size;

    FenTree(int n) {
        size = n;
        t.assign(size, 0);
    }

    void inc(int i, long long value) {
        for (; i < size; i = i | (i + 1))
            t[i] += value;
    }

    long long sum(int i) {
        long long result = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            result += t[i];
        
        return result;
    }
};

struct Operation {
    int l, r;
    long long d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a (n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<Operation> ops (m, {0, 0, 0});
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;

        ops[i].l = l;
        ops[i].r = r;
        ops[i].d = d;
    }

    FenTree amounts (m + 1);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        amounts.inc(x, 1);
        amounts.inc(y + 1, -1);
    }

    FenTree inserts (n + 1);
    for (int i = 0; i < m; i++) {
        long long amnt = amounts.sum(i);

        inserts.inc(ops[i].l, amnt * ops[i].d);
        inserts.inc(ops[i].r + 1, -amnt * ops[i].d);
    }

    for (int i = 0; i < n; i++) {
        long long delta = inserts.sum(i);

        cout << a[i] + delta << " ";
    }
}