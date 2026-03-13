#include <iostream>
#include <list>
#include <map>

using namespace std;

class DSU {
    public:
        int n;
        int* parents;
        // list<int>* contains;
        map<int, list<int>> contains;

        DSU (int n) {
            this->n = n;
            parents = new int[n];
            
            for (int i = 0; i < n; i++){
                parents[i] = i;
                contains[i].push_back(i);
            }
        }

        int findParent(int u){
            return (parents[u] == u) ? (u) : (parents[u] = findParent(parents[u]));
        }

        void unionParents(int u, int v){
            int parentU = findParent(u);
            int parentV = findParent(v);

            if(parentU == parentV)
                return;
            
            contains[parentV].splice(contains[parentV].end(), contains[parentU]);
            contains.erase(parentU);
            parents[parentU] = parentV;
        }
};

int main() {
    int n;
    cin >> n;

    DSU dsu (n);

    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;

        dsu.unionParents(x - 1, y - 1);
    }

    int mainParent = dsu.findParent(0);
    list<int> cont = dsu.contains[mainParent];
    for (auto it = cont.begin(); it != cont.end(); it++){
        cout << (*it) + 1 << " ";
    }
}