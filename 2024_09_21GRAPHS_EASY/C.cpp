#include <iostream>
#include <vector>

using namespace std;

class DSU {
    public:
        vector<int> parents;
        vector<int> counts;
        
        DSU(int n) {
            parents.reserve(n);
            counts.reserve(n);
            for (int i = 0; i < n; i++){
                parents.push_back(i);
                counts.push_back(1);
            }
        }

        int getParent(int u){
            return (parents[u] == u) ? (u) : (parents[u] = getParent(parents[u]));
        }

        void unionParents(int u, int v){
            int parentU = getParent(u);
            int parentV = getParent(v);

            if(parentU == parentV)
                return;
            
            if(counts[parentU] > counts[parentV]){
                parents[parentV] = parentU;
                counts[parentU] += counts[parentV];
            }
            else{
                parents[parentU] = parentV;
                counts[parentV] += counts[parentU];
            }
        }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu (n);

    for (int i = 0; i < m; i++){
        int k;
        cin >> k;

        if(k == 0)
            continue;

        int first;
        cin >> first;
        for (int j = 0; j < k - 1; j++){
            int index;
            cin >> index;

            dsu.unionParents(first - 1, index - 1);
        }
    }

    for (int i = 0; i < n; i++){
        int count = dsu.counts[dsu.getParent(i)];
        cout << count << " ";
    }
}