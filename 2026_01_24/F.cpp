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

struct Node {
    ll min_val;
};

vector<Node> tree;
int tree_size;

void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree[node].min_val = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid) 
        update(2 * node, start, mid, idx, val);
    else 
        update(2 * node + 1, mid + 1, end, idx, val);

    tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
}

int find_last(int node, int start, int end, int l, int r, ll C) {
    if (start > end || start > r || end < l || tree[node].min_val > C) 
        return 0;
    if (start == end) 
        return start;

    int mid = (start + end) / 2;
    int res = find_last(2 * node + 1, mid + 1, end, l, r, C);
    if (res == 0) 
        res = find_last(2 * node, start, mid, l, r, C);
    return res;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<ll> L = {n};
    vector<ll> ops_l = {0}, ops_r = {0};
    tree_size = q;
    tree.assign(4 * q + 1, { LLONG_MAX });

    int op_count = 0;
    for (int k = 0; k < q; ++k) {
        int type;
        cin >> type;

        if (type == 1) {
            ll l, r;
            cin >> l >> r;

            op_count++;
            ll prev_len = L.back();
            L.push_back(prev_len + (r - l + 1));
            ops_l.push_back(l); ops_r.push_back(r);

            update(1, 1, tree_size, op_count, prev_len - r);
        } 
        else {
            ll x;
            cin >> x;

            while (x > n) {
                int j = lower_bound(L.begin(), L.end(), x) - L.begin();
                ll c = L[j] - x;

                int k = find_last(1, 1, tree_size, 1, j, c);
                if (k == 0) 
                    break;
                
                x = L[k] - c;
                
                if (x >= ops_l[k]) 
                    x = ops_l[k] + (x - ops_l[k]) / 2;
            }
            cout << s[x - 1] << "\n";
        }
    }
}