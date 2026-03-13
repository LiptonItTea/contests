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

struct SegmentTree { // i hate this problem...
    int sz;
    vector<ll> tree;

    SegmentTree(int n) {
        sz = 1;
        while (sz < n + 1) 
            sz *= 2;
        tree.assign(2 * sz, LLONG_MAX);
    }

    void update(int i, ll val) {
        i += sz;
        tree[i] = val;

        while (i > 1) {
            i /= 2;
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int find_last_less(int v, int tl, int tr, int l, int r, ll val) {
        if (tl > r || tr < l || tree[v] >= val)
            return -1;
        
        if (tl == tr)
            return tl;
        
        int tm = (tl + tr) / 2;
        int res = find_last_less(2 * v + 1, tm + 1, tr, l, r, val);
        if (res == -1) 
            res = find_last_less(2 * v, tl, tm, l, r, val);
        return res;
    }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<ll> L, ops_l, ops_r;
    L.push_back(n);
    ops_l.push_back(0);
    ops_r.push_back(0);

    SegmentTree st(q);
    int op_count = 0;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            ll l, r;
            cin >> l >> r;

            op_count++;
            ll prev_L = L.back();
            L.push_back(prev_L + (r - l + 1));
            ops_l.push_back(l);
            ops_r.push_back(r);
            st.update(op_count, prev_L - r - 1);
        } 
        else { // type 2
            ll x;
            cin >> x;

            ll current_x = x;
            int current_j = op_count;

            while (current_j > 0) { // fuck
                ll delta = L[current_j] - current_x;

                int k = st.find_last_less(1, 0, st.sz - 1, 1, current_j, delta);
                
                if (k <= 0) 
                    break;

                current_x = L[k] - delta;

                if (current_x >= ops_l[k]) {
                    current_x = ops_l[k] + (current_x - ops_l[k]) / 2;
                }

                current_j = k - 1;
            }

            cout << s[current_x - 1] << "\n";
        }
    }

    return 0;
}