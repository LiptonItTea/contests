#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct DSU {
    vector<int> parent;

    int findParent(int u) {
        return (u == parent[u]) ? (u) : (parent[u] = findParent(parent[u]));
    }

    void unionParent(int u, int v) {
        int parentU = parent[u];
        int parentV = parent[v];

        parent[parentV] = parentU;
    }
};

vector<vector<int>> children;
DSU dsu;
vector<pair<int, int>> originalQueries;
vector<vector<int>> bucketedQueries;
map<pair<int, int>, int> answers;

void dfs(int currNode, DSU& dsu) {
    dsu.parent[currNode] = currNode;

    for (int nextNode : children[currNode]) {
        dfs(nextNode, dsu);
        dsu.unionParent(currNode, nextNode);
    }

    for (int i = 0; i < bucketedQueries[currNode].size(); i++) {
        int checking = bucketedQueries[currNode][i];
        if (dsu.parent[checking] != -1) {
            answers[{currNode, bucketedQueries[currNode][i]}] = dsu.findParent(checking);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
    // cout << "started\n";

    int k;
    cin >> k;

    children.push_back({});
    bucketedQueries.push_back({});

    for (int i = 0; i < k; i++) {
        string type;
        int a, b;
        cin >> type >> a >> b;
        a--; b--;

        if (type == "ADD") {
            children.push_back({});
            children[a].push_back(b);

            bucketedQueries.push_back({});
        }
        else {
            originalQueries.push_back({a, b});

            bucketedQueries[a].push_back(b);
            bucketedQueries[b].push_back(a);
        }
    }

    dsu.parent.assign(children.size(), -1);
    dfs(0, dsu);

    for (pair<int, int> q : originalQueries) {
        if (answers.find({q.first, q.second}) != answers.end()) {
            cout << answers[{q.first, q.second}] + 1 << "\n";
        }
        else{
            cout << answers[{q.second, q.first}] + 1<< "\n";
        }
    }
}