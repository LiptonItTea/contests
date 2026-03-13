#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dfsCounter = 0;
vector<vector<int>> p;
vector<int> tin, tout;
vector<vector<int>> children;

void dfs(int prevNode, int currNode, int n, int log2n) {
    cout << currNode << "\n";
    tin[currNode] = dfsCounter++;

    p[currNode][0] = prevNode;
    for (int i = 1; i < log2n; i++)
        p[currNode][i] = p[p[currNode][i - 1]][i - 1];

    for (int next : children[currNode]) {
        dfs(currNode, next, n, log2n);
    }

    tout[currNode] = dfsCounter++;
}

int log2(int n) {
    int i = 0;
    int c = 1;
    while (c < n) {
        c <<= 1;
        i++;
    }

    return i;
}

bool isAnc(int a, int b) {
    if (tin[a] <= tin[b] && tout[b] <= tout[a])
        return true;
    return false;
}

int main() {
    freopen("test.in", "r", stdin);
    // freopen("lca.out", "w", stdout);

    cout << "started\n";
    int k;
    cin >> k;

    children.push_back({});

    vector<pair<int, int>> getQueries; getQueries.reserve(k);

    for (int i = 0; i < k; i++) {
        string type;
        int a, b;
        cin >> type >> a >> b;
        a--;b--;

        if (type == "ADD") {
            children.push_back({});
            children[a].push_back(b);
        }
        else {
            //GET
            getQueries.push_back({a, b});
        }
    }

    int n = children.size();
    int log2n = log2(n) + 1;

    p.assign(n, vector<int> (log2n, -1));
    tin.assign(n, -1);
    tout.assign(n, -1);
    dfs(0, 0, n, log2n);

    for (int i = 0; i < getQueries.size(); i++) {
        int a = getQueries[i].first,
            b = getQueries[i].second;
        
        if (isAnc(a, b)){
            cout << a + 1 << "\n";
            continue;
        }

        if (isAnc(b, a)){
            cout << b + 1 << "\n";
            continue;
        }

        int l = log2n - 1;
        //jump
        while (l >= 0) {
            if (isAnc(p[a][l], b)){
                l--;
                continue;
            }

            //not an ancestor
            a = p[a][l];
        }

        cout << p[a][0] + 1 << "\n";
    }
}