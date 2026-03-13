#include <iostream>
#include <vector>
#include <climits>

#define ll long long

using namespace std;

int near2(int n) {
    int c = 1;
    while (c < n)
        c <<= 1;
    return c;
}

struct SegTree {
    vector<ll> a;
    vector<ll> b;
    vector<ll> d;
    int size;
    int source_size;

    SegTree(vector<int> source) {
        source_size = source.size();
        size = near2(source.size());
        a.assign(size, 0);
        for (int i = 0; i < source.size(); i++)
            a[i] = source[i];
        
        b.assign(2 * size, LLONG_MIN);
        d.assign(2 * size, LLONG_MAX);
    }

    void build() {
        build(0, 0, size - 1);
    }

    void build(int v, int l, int r) {
        if (l == r) {
            b[v] = a[l];
            if (l >= source_size)
                b[v] = LLONG_MIN;
            d[v] = a[l];
            if (l >= source_size)
                d[v] = LLONG_MAX;
        }
        else {
            int c = (l + r) / 2;
            build(v * 2 + 1, l, c);
            build(v * 2 + 2, c + 1, r);
            b[v] = max(b[v * 2 + 1], b[v * 2 + 2]);
            d[v] = min(d[v * 2 + 1], d[v * 2 + 2]);
        }
    }

    ll find_max(int i, int j) {
        return find_max(i, j, 0, 0, size - 1);
    }

    ll find_max(int i, int j, int v, int l, int r) {
        if (r < i || j < l) {
            return LLONG_MIN;
        }

        if (i <= l && r <= j) {
            return b[v];
        }

        int c = (l + r) / 2;
        return max(find_max(i, j, v * 2 + 1, l, c), find_max(i, j, v * 2 + 2, c + 1, r));
    }

    ll find_min(int i, int j) {
        return find_min(i, j, 0, 0, size - 1);
    }

    ll find_min(int i, int j, int v, int l, int r) {
        if (r < i || j < l) {
            return LLONG_MAX;
        }

        if (i <= l && r <= j) {
            return d[v];
        }

        int c = (l + r) / 2;
        return min(find_min(i, j, v * 2 + 1, l, c), find_min(i, j, v * 2 + 2, c + 1, r));
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> history (n, 0);
    for (int i = 0; i < n; i++)
        cin >> history[i];

    SegTree sg (history);
    sg.build();

    ll best_feature = LLONG_MIN;
    for (int i = k - 1; i < n; i++) {
        best_feature = max(best_feature, sg.find_max(i - k + 1, i) * sg.find_min(i - k + 1, i));
    }

    cout << best_feature;
}