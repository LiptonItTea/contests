#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct DSU {
    vector<pair<int, int>> parents;
    stack<pair<int, pair<int, int>>> history;
    stack<int> timeStamps;

    DSU (int n) {
        parents.reserve(n);

        for (int i = 0; i < n; i++)
            parents.push_back({i, 0});
    }

    pair<int, int> getParents(int u) {
        if (u == parents[u].first)
            return parents[u];
        int len = parents[u].second;
        pair<int, int> parent = getParents(parents[u].first);

        if (parents[u].first != parent.first)
            history.push({u, parents[u]});
        parents[u] = parent;
        parents[u].second += len;

        return parents[u];
    }

    bool unionParents(int u, int v){
        pair<int, int> parentU = getParents(u);
        pair<int, int> parentV = getParents(v);

        if (parentU.first == parentV.first)
            return false;
        timeStamps.push(history.size()); //todo bad
        history.push({parentV.first, parents[parentV.first]});
        parents[parentV.first] = {parentU.first, 1};
        
        return true;
    }

    void revertEdge() {
        int timeStamp = timeStamps.top(); timeStamps.pop();
        while (history.size() > timeStamp) {
            pair<int, pair<int, int>> p = history.top();
            history.pop();

            parents[p.first] = p.second;
        }
    }
};

int main() {
    DSU dsu (4);
    dsu.unionParents(0, 1);
    dsu.unionParents(0, 2);
    dsu.unionParents(1, 3);
    dsu.revertEdge();
    dsu.revertEdge();
    dsu.revertEdge();
    dsu.unionParents(0, 1);
    dsu.unionParents(2, 3);
    dsu.unionParents(1, 2);
    dsu.getParents(2);
    dsu.revertEdge();
}