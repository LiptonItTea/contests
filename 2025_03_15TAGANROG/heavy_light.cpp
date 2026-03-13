#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

#define ll long long

using namespace std;

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

    void construct(vector<int>& source) {
        size = nearest2(source.size());

        a.assign(size, INT_MIN);
        b.assign(2 * size, INT_MIN);
        for (int i = 0; i < source.size(); i++) {
            a[i] = source[i];
        }
    }

    void build() {build(0, 0, size - 1);};
    int getMax(int i, int j) {return getMax(i, j, 0, 0, size - 1);};

    void build(int v, int l, int r) {
        if (l == r) {
            b[v] = a[l];
            return;
        }

        int c = (l + r) / 2;
        build(v * 2 + 1, l, c);
        build(v * 2 + 2, c + 1, r);
        b[v] = max(b[v * 2 + 1], b[v * 2 + 2]);
    }

    int getMax(int i, int j, int v, int l, int r) {
        if (r < i || j < l) {
            return 0;
        }

        if (i <= l && r <= j) {
            return b[v];
        }

        int c = (l + r) / 2;
        return max(getMax(i, j, v * 2 + 1, l, c), getMax(i, j, v * 2 + 2, c + 1, r));
    }
};

struct Edge {
    int to;
    int cost;
    bool heavy = false;
};

struct Node {
    int id;
    vector<Edge> links;

    int prev = 0;
    Edge prevEdge = {-1, -1};
    int subAmount = 0;
    bool has_heavy = false;
    Edge heavy_edge = {-1, -1};
    bool visited = false;
};

vector<Node> nodes;
int root = 0;

void dfs_count(int curr, int prev) {
    for (Edge e : nodes[curr].links) {
        if (e.to == prev) {
            continue;
        }
        
        nodes[e.to].prev = curr;
        nodes[e.to].prevEdge = e;
        dfs_count(e.to, curr);
    }

    
    int cumul = 1;
    for (Edge e : nodes[curr].links) {
        cumul += nodes[e.to].subAmount;
    }
    nodes[curr].subAmount = cumul;

    for (Edge e : nodes[curr].links) {
        if (e.to == prev)
            continue;
        
        if (2 * nodes[e.to].subAmount >= nodes[curr].subAmount) {
            e.heavy = true;
            nodes[curr].has_heavy = true;
            nodes[curr].heavy_edge = e;
        }
    }
}

struct Path {
    int start;
    int end;
    map<int, int> nodesPos;
    vector<int> wholeCosts;
    SegTree st;
};
vector<Path> hld;
void dfs_hl() {
    for (int i = 0; i < nodes.size(); i++) {
        int curr = i;
        if (!nodes[curr].has_heavy) {
            Path path;
            path.start = curr;
            int j = 0;
            path.nodesPos[curr] = j++;

            int prev = curr;
            curr = nodes[curr].prev;
            while (nodes[curr].heavy_edge.heavy && nodes[curr].heavy_edge.to == prev) {
                path.nodesPos[curr] = j++;
                path.wholeCosts.push_back(nodes[curr].heavy_edge.cost);
                
                prev = curr;
                curr = nodes[curr].prev;
                if (curr == root) // root
                    break;
            }
            path.nodesPos[curr] = j++;
            path.wholeCosts.push_back(nodes[prev].prevEdge.cost);
            path.end = curr;

            path.st = SegTree();
            path.st.construct(path.wholeCosts);
            path.st.build();
        
            hld.push_back(path);
        }
    }
}

int hl_search(int u) {
    int index = -1;
    for (int i = 0; i < hld.size(); i++) {
        if (hld[i].nodesPos.find(u) != hld[i].nodesPos.end()) {
            index = i;
            break;
        }
    }
    return index;
}

int hl_solve(int u, int l) {
    int startPathIndex = hl_search(u);
    int maxEdge = -1;

    if (hld[startPathIndex].nodesPos.find(l) != hld[startPathIndex].nodesPos.end()){
        int i = hld[startPathIndex].nodesPos[u];
        int j = hld[startPathIndex].nodesPos[l];
        if (i > j)
            swap(i, j);

        maxEdge = hld[startPathIndex].st.getMax(i, j - 1);
        return maxEdge;
    }
    
    int prevPathIndex = -1;
    int currPathIndex = startPathIndex;

    int i = hld[startPathIndex].nodesPos[u];
    int j = hld[startPathIndex].nodesPos.size() - 1;
    maxEdge = hld[startPathIndex].st.getMax(i, j);

    while (hld[currPathIndex].nodesPos.find(l) == hld[currPathIndex].nodesPos.end()) {
        prevPathIndex = currPathIndex;
        currPathIndex = hl_search(hld[currPathIndex].end);

        if (hld[currPathIndex].nodesPos.find(l) == hld[currPathIndex].nodesPos.end()) {
            i = hld[currPathIndex].nodesPos[hld[prevPathIndex].end];
            j = hld[currPathIndex].nodesPos.size() - 1;
            maxEdge = max(maxEdge, hld[currPathIndex].st.getMax(i, j));
        }
    }

    i = hld[currPathIndex].nodesPos[hld[prevPathIndex].end];
    j = hld[currPathIndex].nodesPos[l];
    maxEdge = max(maxEdge, hld[currPathIndex].st.getMax(i, j));

    return maxEdge;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // dsu = DSU(n);

    nodes.assign(n, {-1, {}});
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        nodes[u - 1].links.push_back({v - 1, c});
        nodes[v - 1].links.push_back({u - 1, c});
    }

    root = 0;

    dfs_count(0, -1);
    dfs_hl();

    cout << hl_solve(5, 0);
}