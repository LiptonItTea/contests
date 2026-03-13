#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <random>

#define ll long long

using namespace std;

struct DSU {
    vector<int> p;

    DSU (int n) {
        p.assign(n, 0);

        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int getParent(int u) {
        return (u == p[u]) ? (u) : (p[u] = getParent(p[u]));
    }

    void unionParents(int u, int v) {
        int parentu = getParent(u);
        int parentv = getParent(v);

        p[parentv] = parentu;
    }
};

int nearest2(int n) {
    int c = 1;
    while (c < n)
        c <<= 1;
    return c;
}

struct SegTree {
    int size;
    vector<int> a;
    vector<int> b;

    SegTree (int n) {
        size = nearest2(n);

        a.assign(size, 0);
        b.assign(2 * size, 0);
    }

    void build(int v, int l, int r) {
        if (l == r) {
            b[l] = a[v];
            return;
        }

        int c = (l + r) / 2;
        build(v * 2 + 1, l, c);
        build(v * 2 + 2, c + 1, r);
        b[v] = b[v * 2 + 1] + b[v * 2 + 2];
    }

    int getSum(int i, int j, int v, int l, int r) {
        if (r < i || j < l) {
            return 0;
        }

        if (i <= l && r <= j) {
            return b[v];
        }

        int c = (l + r) / 2;
        return getSum(i, j, v * 2 + 1, l, c) + getSum(i, j, v * 2 + 2, c + 1, r);
    }

    void change(int i, int value, int v, int l, int r) {
        if (l == r) {
            a[i] = value;
            b[i] = value;
            return;
        }

        int c = (l + r) / 2;
        if (i <= c)
            change(i, value, v * 2 + 1, l, c);
        else
            change(i, value, v * 2 + 2, c + 1, r);
        b[v] = b[v * 2 + 1] + b[v * 2 + 2];
    }
};

struct FenTree {
    
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    srand(42u);
    for (int i = 0; i < 10; i++)
        cout << rand() % 256 << " ";

    // int t;
    // cin >> t;

    // for (int _ = 0; _ < t; _++) {

    // }
}