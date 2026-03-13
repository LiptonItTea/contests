#include <iostream>
#include <set>
#include <list>
#include <vector>

using namespace std;

class DSU {
    public:
        int n;
        int* parents;

        DSU (int n){
            this->n = n;
            parents = new int[n];
            for (int i = 0; i < n; i++){
                parents[i] = i;
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
            
            parents[parentU] = parentV;
        }
};

class Node {
    public:
        list<Node*> links;
        int color = 0;
};

bool dfs(Node* curr, Node* prev){
    if(prev != nullptr){
        curr->color = (prev->color == 1) ? 2 : 1;
    }
    else{
        curr->color = 1;
    }

    for (Node* next : curr->links){
        if(next == prev)
            continue;
        
        if(next->color != 0){
            if(next->color == curr->color){
                return false;
            }
            continue;
        }
        
        bool result = dfs(next, curr);
        if(!result)
            return false;
    }

    return true;
}

int main () {
    int n, m;
    cin >> n >> m;

    DSU dsu (n);

    set<pair<int, int>> friends;
    set<pair<int, int>> enemies;
    for (int i = 0; i < m; i++){
        int x, y, t;
        cin >> x >> y >> t;

        if(t == 1)
            friends.insert({x - 1, y - 1});
        else
            enemies.insert({x - 1, y - 1});
    }

    for (pair<int, int> p : friends){
        dsu.unionParents(p.first, p.second);
    }
    
    set<int> groups;
    for (int i = 0; i < n; i++){
        groups.insert(dsu.parents[i]);
    }
    
    vector<Node*> nodes;
    nodes.reserve(n);
    for (int i = 0; i < n; i++){
        Node* node = new Node;
        nodes.push_back(node);
    }

    for (pair<int, int> p : enemies){
        int parentU = dsu.getParent(p.first);
        int parentV = dsu.getParent(p.second);
        if(parentU == parentV){
            cout << "NO";
            return 0;
        }

        nodes[parentU]->links.push_back(nodes[parentV]);
        nodes[parentV]->links.push_back(nodes[parentU]);
    }
    for (int i = 0; i < n; i++){
        Node* node = nodes[i];

        if(node->color == 0){
            bool result = dfs(node, nullptr);
            
            if(!result){
                cout << "NO";
                return 0;
            }
        }
    }
    
    // for (int i = 0; i < n; i++){
    //     cout << dsu.parents[i] << " ";
    // }
    // cout << "\n";

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        int parent = dsu.getParent(i);
        cout << nodes[parent]->color << " ";
    }
}