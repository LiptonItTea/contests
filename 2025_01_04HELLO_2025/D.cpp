#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int near2(int n) {
    int c = 1;
    while (c < n)
        c <<= 1;
    return c;
}

struct Segtree {
    vector<ll> a;
    vector<ll> b1; // max
    vector<ll> b2; // max
    vector<ll> c1; // min
    vector<ll> c2; // min
    vector<ll> d; // target
    int size;
    int orig_size;

    Segtree(vector<int>& source) {
        size = near2(source.size());
        orig_size = source.size();
        a.assign(size, 0);
        b1.assign(2 * size, 0);
        b2.assign(2 * size, 0);
        c1.assign(2 * size, 0);
        c2.assign(2 * size, 0);
        d.assign(2 * size, 0);

        for (int i = 0; i < orig_size; i++)
            a[i] = source[i];
    }

    void build(int v, int l, int r) {
        if (l == r) {
            if (l < orig_size) {
                b1[v] = a[l] - (l + 1);
                b2[v] = a[l] + (l + 1);
                c1[v] = a[l] - (l + 1);
                c2[v] = a[l] + (l + 1);
                d[v] = 0;
            }
            else {
                b1[v] = INT_MIN;
                b2[v] = INT_MIN;
                c1[v] = INT_MAX;
                c2[v] = INT_MAX;
                d[v] = INT_MIN;
            }
        }
        else {
            int mid = (l + r) / 2;
            build(v * 2 + 1, l, mid);
            build(v * 2 + 2, mid + 1, r);

            b1[v] = max(b1[v * 2 + 1], b1[v * 2 + 2]);
            b2[v] = max(b2[v * 2 + 1], b2[v * 2 + 2]); 
            c1[v] = min(c1[v * 2 + 1], c1[v * 2 + 2]);
            c2[v] = min(c2[v * 2 + 1], c2[v * 2 + 2]);
            d[v] = max(
                d[v * 2 + 1], 
                max(
                    d[v * 2 + 2], 
                    max(
                        b1[v * 2 + 2] - c1[v * 2 + 1],
                        b2[v * 2 + 1] - c2[v * 2 + 2]
                    )
                )
            );
        }
    }

    ll get() {
        return d[0];
    }

    void update(int p, int x, int v, int l, int r) {
        if (l == r) {
            b1[v] = x - (p + 1);
            b2[v] = x + (p + 1);
            c1[v] = x - (p + 1);
            c2[v] = x + (p + 1);
            d[v] = 0;
        }
        else {
            int mid = (l + r) / 2;
            if (p <= mid)
                update(p, x, v * 2 + 1, l, mid);
            else {
                update(p, x, v * 2 + 2, mid + 1, r);
            }

            b1[v] = max(b1[v * 2 + 1], b1[v * 2 + 2]);
            b2[v] = max(b2[v * 2 + 1], b2[v * 2 + 2]); 
            c1[v] = min(c1[v * 2 + 1], c1[v * 2 + 2]);
            c2[v] = min(c2[v * 2 + 1], c2[v * 2 + 2]);
            d[v] = max(
                d[v * 2 + 1], 
                max(
                    d[v * 2 + 2], 
                    max(
                        b1[v * 2 + 2] - c1[v * 2 + 1],
                        b2[v * 2 + 1] - c2[v * 2 + 2]
                    )
                )
            );
        }
    }

    void build() {
        build(0, 0, size - 1);
    }

    void update(int p, int x) {
        update(p, x, 0, 0, size - 1);
    }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, q;
        cin >> n >> q;

        vector<int> a (n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        Segtree st (a);
        st.build();
        cout << st.get() << "\n";

        for (int i = 0; i < q; i++) {
            int p, x;
            cin >> p >> x;

            st.update(p - 1, x);
            cout << st.get() << "\n";
        }
    }
}