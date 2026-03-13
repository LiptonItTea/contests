#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DSU {
    private:
        int* parents;
        int n;
    public:
        DSU (int n){
            this->n = n;
            parents = new int[n];
            for (int i = 0; i < n; i++)
                parents[i] = i;
        }
        void unionNodes(int u, int v){
            int parentU = getNode(u);
            int parentV = getNode(v);

            parents[parentV] = parentU;
        }
        int getNode(int u){
            int curr = u;
            while(curr != parents[curr]){
                curr = parents[curr];
            }

            //relink
            int parent = curr;
            int prev;
            curr = u;
            while(curr != parents[curr]){
                prev = curr;
                curr = parents[curr];

                parents[prev] = parent;
            }

            return curr;
        }
};

int main(){
    int n, m;
    cin >> n >> m;

    DSU dsu (n);

    for (int i = 0; i < m; i++){
        string type;
        int u, v;

        cin >> type >> u >> v;

        if(type == "union"){
            dsu.unionNodes(u - 1, v - 1);
        }
        else{
            int parentU = dsu.getNode(u - 1);
            int parentV = dsu.getNode(v - 1);

            if(parentU == parentV){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}