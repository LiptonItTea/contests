#include <iostream>
#include <vector>

using namespace std;

int near2(int n) {
    int c = 1;
    while (c < n)
        c <<= 1;
    return c;
}

struct SegTree {
    int size;
    vector<int> a;
    vector<int> b;

    SegTree (vector<int>& source) {
        size = near2(source.size());
        a.assign(size, INT_MAX);
        b.assign(2 * size, INT_MAX);

        for (int i = 0; i < source.size(); i++)
            a[i] = source[i];
    }

    void build() {
        build(0, 0, size - 1);
    }

    void build(int v, int l, int r) {
        if (l == r) {
            b[v] = a[l];
            return;
        }

        int c = (l + r) / 2;
        build(v * 2 + 1, l, c);
        build(v * 2 + 2, c + 1, r);
        b[v] = min(b[v * 2 + 1], b[v * 2 + 2]);
    }

    int findMin(int i, int j) {
        return findMin(i, j, 0, 0, size - 1);
    }

    int findMin(int i, int j, int v, int l, int r) {
        if (r < i || j < l) 
            return INT_MAX;
        
        if (i <= l && r <= j)
            return b[v];
        
        int c = (l + r) / 2;
        return min(findMin(i, j, v * 2 + 1, l, c), findMin(i, j, v * 2 + 2, c + 1, r));
    }
};

int n, m;

vector<vector<int>> children;
vector<int> order;
vector<int> orderHeights;
vector<int> heights;
vector<int> first;

void dfs(int currNode, int currHeight) {
    heights[currNode] = currHeight;
    order.push_back(currNode);
    orderHeights.push_back(currHeight);
    first[currNode] = order.size() - 1;

    for (int nextNode : children[currNode]) {
        dfs(nextNode, currHeight + 1);
        order.push_back(currNode);
        orderHeights.push_back(currHeight);
    }

    order.push_back(currNode);
    orderHeights.push_back(currHeight);
}

vector<long long> as;
long long a1, a2, x, y, z;
long long getA(int i) {
    if (i <= as.size())
        return as[i - 1];
    
    for (int j = as.size(); j <= i; j++) {
        as[j] = ((x * as[j - 2]) % n + (y * as[j - 1]) % n + z) % n;
    }

    return as[i];
}

int main() {
    cin >> n >> m;

    children.assign(n, {});
    heights.assign(n, -1);
    first.assign(n, -1);
    order.reserve(2 * n);
    orderHeights.reserve(2 * n);

    as.reserve(2 * m);
    
    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;

        if (p == 0)
            continue;

        children[p].push_back(i);
    }

    dfs(0, 0);

    SegTree sg (orderHeights);

    cin >> a1 >> a2 >> x >> y >> z;
    as.push_back(a1);
    as.push_back(a2);

    cout << 
    for (int i = 0; i < m; i++) {

    }
}