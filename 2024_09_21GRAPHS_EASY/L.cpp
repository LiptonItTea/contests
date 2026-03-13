#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Node {
    public:
        int id;
        int status = 0;
        vector<Node*> inLinks;
        vector<Node*> outLinks;
        vector<Node*> unordLinks;
};

class DSU {
    public:
        vector<int> parent;

        DSU (int n){
            parent.reserve(n);
            for (int i = 0; i < n; i++){
                parent.push_back(i);
            }
        }

        int getParent(int u){
            return (u == parent[u]) ? (u) : (parent[u] = getParent(parent[u]));
        }

        void unionParent(int u, int v){
            int parentU = parent[u];
            int parentV = parent[v];

            if (parentU == parentV)
                return;
            
            parent[parentV] = parentU;
        }
};

bool topSortNoUnord(deque<Node*>& order, Node* curr, Node* prev){
    curr->status = 1;

    for (Node* next : curr->outLinks){
        if (next->status == 1)
            return true;
        
        if (next->status == 2)
            continue;
        
        bool cycle = topSortNoUnord(order, next, curr);
        if (cycle)
            return true;
    }

    curr->status = 2;
    order.push_front(curr);
    return false;
}

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, m;
        cin >> n >> m;

        vector<Node*> nodes (n);
        for (int i = 0; i < n; i++){
            Node* node = new Node;
            node->id = i + 1;
            nodes[i] = node;
        }

        DSU dsu (n);

        for (int i = 0; i < m; i++){
            int type, x, y;
            cin >> type >> x >> y;

            if (type == 0){
                nodes[x - 1]->unordLinks.push_back(nodes[y - 1]);
                nodes[y - 1]->unordLinks.push_back(nodes[x - 1]);
            }
            else{
                nodes[x - 1]->outLinks.push_back(nodes[y - 1]);
                nodes[y - 1]->inLinks.push_back(nodes[x - 1]);
            }

            dsu.unionParent(x - 1, y - 1);
        }

        map<int, vector<Node*>> dict;
        for (int i = 0; i < n; i++){
            int index = dsu.getParent(i);

            dict[index].push_back(nodes[i]);
        }

        for (auto it = dict.begin(); it != dict.end(); it++){
            vector<Node*> component = it->second;
            deque<Node*> order;

            for (Node* node : component) {
                if (node->status == 0 && node->inLinks.size() == 0) {
                    bool cycle = topSortNoUnord(order, node, nullptr);
                    
                    if(cycle) {
                        cout << "NO";
                        return 0;
                    }
                }
            }

            map<Node*, int> indexes;
            int i = 0;
            for (Node* node : order){
                indexes[node] = i++;
            }

            for (Node* node : component) {
                for (Node* next : node->unordLinks){
                    if(indexes[node] < indexes[next]){
                        node->outLinks.push_back(next);
                    }
                    else{
                        next->inLinks.push_back(next);
                    }
                }
            }
        }

        cout << "YES\n";
        for (Node* node : nodes) {
            for (Node* next : node->outLinks){
                cout << node->id << " " << next->id << "\n";
            }
        }
    }
}