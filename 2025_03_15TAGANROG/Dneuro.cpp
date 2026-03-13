#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdexcept>

using namespace std;

const int N = 2000002;
const int LOG = 20;

struct Edge {
    int weight;
    int deeper_end;
    Edge(int w = 0, int de = 0) : weight(w), deeper_end(de) {}
};

struct treeNode {
    int par = -1;
    int depth = 0;
    int size = 0;
    int pos_segbase = 0;
    int chain = 0;
    int tin = 0;
    int tout = 0;
    int up[LOG + 1];
    
    treeNode() {
        memset(up, -1, sizeof(up));
    }
};

struct segmentTree {
    vector<int> base_array;
    vector<int> tree;
    
    segmentTree() : base_array(N), tree(6 * N, -1) {}
};

vector<pair<int, int>> adjacencyList[N];
treeNode node[N];
Edge edge[N];
segmentTree s;
int edge_counted = 0;
int curr_chain = 0;
int timer = 0;

void addEdge(int e, int u, int v, int w) {
    if (u < 1 || v < 1 || e < 1) {
        throw invalid_argument("Node and edge indices must be 1-based");
    }
    int uIndex = u - 1;
    int vIndex = v - 1;
    int edgeIndex = e - 1;
    
    adjacencyList[uIndex].emplace_back(vIndex, edgeIndex);
    adjacencyList[vIndex].emplace_back(uIndex, edgeIndex);
    edge[edgeIndex] = Edge(w, 0);
}

void dfs(int curr, int prev, int dep, int n) {
    node[curr].par = prev;
    node[curr].depth = dep;
    node[curr].tin = ++timer;
    node[curr].up[0] = (prev != -1) ? prev : curr;
    
    for (int i = 1; i <= LOG; ++i) {
        if (node[curr].up[i-1] == -1) {
            node[curr].up[i] = -1;
        } else {
            node[curr].up[i] = node[node[curr].up[i-1]].up[i-1];
        }
    }
    
    for (auto& neighbor : adjacencyList[curr]) {
        int j = neighbor.first;
        if (j != prev) {
            int edgeIndex = neighbor.second;
            if (edgeIndex >= 0 && edgeIndex < N) {
                edge[edgeIndex].deeper_end = j;
            }
            dfs(j, curr, dep + 1, n);
            node[curr].size += node[j].size;
        }
    }
    node[curr].tout = ++timer;
}

bool upper(int a, int b) {
    return node[a].tin <= node[b].tin && node[a].tout >= node[b].tout;
}

int LCA(int a, int b) {
    if (a == b) return a;
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    
    for (int i = LOG; i >= 0; --i) {
        if (node[a].up[i] != -1 && !upper(node[a].up[i], b)) {
            a = node[a].up[i];
        }
    }
    return node[a].up[0];
}

void hld(int curr_node, int id, int n, int chain_heads[]) {
    if (chain_heads[curr_chain] == -1) {
        chain_heads[curr_chain] = curr_node;
    }
    
    node[curr_node].chain = curr_chain;
    node[curr_node].pos_segbase = edge_counted;
    s.base_array[edge_counted++] = edge[id].weight;
    
    int spcl_chld = -1, spcl_edg_id = 0;
    for (auto& neighbor : adjacencyList[curr_node]) {
        int j = neighbor.first;
        if (j != node[curr_node].par) {
            if (spcl_chld == -1 || node[spcl_chld].size < node[j].size) {
                spcl_chld = j;
                spcl_edg_id = neighbor.second;
            }
        }
    }
    
    if (spcl_chld != -1) {
        hld(spcl_chld, spcl_edg_id, n, chain_heads);
    }
    
    for (auto& neighbor : adjacencyList[curr_node]) {
        int j = neighbor.first;
        if (j != node[curr_node].par && j != spcl_chld) {
            curr_chain++;
            hld(j, neighbor.second, n, chain_heads);
        }
    }
}

int construct_ST(int ss, int se, int si) {
    if (ss == se - 1) {
        s.tree[si] = s.base_array[ss];
        return s.tree[si];
    }
    
    int mid = (ss + se) / 2;
    s.tree[si] = max(construct_ST(ss, mid, si * 2), 
                    construct_ST(mid, se, si * 2 + 1));
    return s.tree[si];
}

int RMQUtil(int ss, int se, int qs, int qe, int index) {
    if (qs <= ss && qe >= se - 1) return s.tree[index];
    if (se - 1 < qs || ss > qe) return -1;
    
    int mid = (ss + se) / 2;
    return max(RMQUtil(ss, mid, qs, qe, 2 * index),
               RMQUtil(mid, se, qs, qe, 2 * index + 1));
}



int RMQ(int qs, int qe, int n) {
    if (qs < 0 || qe > n - 1 || qs > qe) return -1;
    return RMQUtil(0, n, qs, qe, 1);
}

int crawl_tree(int u, int v, int n, int chain_heads[]) {
    int chain_v = node[v].chain;
    int ans = 0;
    
    while (true) {
        int chain_u = node[u].chain;
        if (chain_u == chain_v) {
            if (u != v) {
                ans = max(ans, RMQ(node[v].pos_segbase + 1, node[u].pos_segbase, n));
            }
            break;
        } else {
            ans = max(ans, RMQ(node[chain_heads[chain_u]].pos_segbase, node[u].pos_segbase, n));
            u = node[chain_heads[chain_u]].par;
        }
    }
    return ans;
}

int maxEdge(int u, int v, int n, int chain_heads[]) {
    int lca = LCA(u, v);
    return max(crawl_tree(u, lca, n, chain_heads), 
              crawl_tree(v, lca, n, chain_heads));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(i, u, v, w);
    }
    
    dfs(0, -1, 0, n);
    
    int chain_heads[N];
    memset(chain_heads, -1, sizeof(chain_heads));
    hld(0, 0, n, chain_heads);
    construct_ST(0, edge_counted, 1);
    
    long long sum = 0;
    int u;
    cin >> u;
    u--;
    
    for (int i = 1; i < m; ++i) {
        int v;
        cin >> v;
        v--;
        sum += maxEdge(u, v, n, chain_heads);
        u = v;
    }
    
    cout << sum << '\n';
    return 0;
}
