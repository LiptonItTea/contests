#include <iostream>
#include <set>
#include <vector>

using namespace std;

class CompareNodes {
    public:
        bool operator()(const long long* left, const long long* right) const {
            if(left[1] != right[1])
                return left[1] < right[1];
            
            return left[0] < right[0];
        }
};

class DSU {
    public:
        long long** parents;
        int n;
        set<long long*, CompareNodes>* tree;

        DSU(int n, long long* values) {
            this->n = n;
            parents = new long long*[n];
            tree = new set<long long*, CompareNodes>;
            for (int i = 0; i < n; i++){
                parents[i] = new long long[2];
                parents[i][0] = i;
                parents[i][1] = values[i];
                // tree->insert(parents[i]);
            }
        }

        long long getParent(long long u){
            return (parents[u][0] == u) ? (u) : (parents[u][0] = getParent(parents[u][0]));
        }

        void unionParents(long long u, long long v){
            long long parentU = getParent(u);
            long long parentV = getParent(v);

            if(parentU == parentV)
                return;
            
            parents[parentU][0] = parentV;

            tree->erase(parents[parentV]);
            parents[parentV][1] += parents[parentU][1];
            tree->insert(parents[parentV]);
        }

        void reveal(long long u){
            tree->insert(parents[u]);
        }
};

int main(){
    int n;
    cin >> n;

    long long* array = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    int* perm = new int[n];
    for (int i = 0; i < n; i++)
        cin >> perm[i];
    
    bool* revealed = new bool[n];
    for (int i = 0; i < n; i++)
        revealed[i] = false;

    DSU dsu (n, array);

    vector<long long> answers;
    answers.reserve(n);
    answers.push_back(0);
    for (int i = n - 1; i >= 1; i--){
        int currPerm = perm[i];
        revealed[currPerm - 1] = true;
        dsu.reveal(currPerm - 1);

        if(currPerm != 1 && revealed[currPerm - 2])
            dsu.unionParents(currPerm - 2, currPerm - 1);
        if(currPerm != n && revealed[currPerm])
            dsu.unionParents(currPerm - 1, currPerm);
        
        answers.push_back((*dsu.tree->rbegin())[1]);
    }

    for (auto it = answers.rbegin(); it != answers.rend(); it++){
        cout << *it << "\n";
    }
}