#include <iostream>
#include <vector>
#include <set>

using namespace std;

class DSU {
    public:
        vector<int> parents;

        DSU (int n){
            parents.reserve(n);
            for (int i = 0; i < n; i++)
                parents.push_back(i);
        }

        int getParent(int u){
            return (parents[u] == u) ? (u) : (parents[u] = getParent(parents[u]));
        }

        void unionParents(int u, int v){
            int parentU = getParent(u);
            int parentV = getParent(v);

            if(parentU == parentV)
                return;
            
            parents[parentV] = parentU;
        }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu (n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        dsu.unionParents(a - 1, b - 1);
    }

    //count components
    set<int> setComponents;
    for (int i = 0; i < n; i++)
        setComponents.insert(dsu.getParent(i));
    
    vector<int> components (setComponents.begin(), setComponents.end());
    cout << components.size() - 1 << "\n";
    for (int j = 1; j < components.size(); j++){
        cout << components[0] + 1 << " " << components[j] + 1 << "\n";
    }
}