#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Node {
    public:
        list<Node*> links;
        bool visited = false;
};

bool dfs(Node* curr, Node* prev){
    curr->visited = true;

    for (Node* next : curr->links){
        if(next == prev)
            continue;
        
        if(next->visited)
            return true;
        
        bool result = dfs(next, curr);
        if(result)
            return true;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Node*> nodes; nodes.reserve(n);
    for (int i = 0; i < n; i++){
        nodes.push_back(new Node);
    }

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        nodes[u - 1]->links.push_back(nodes[v - 1]);
        nodes[v - 1]->links.push_back(nodes[u - 1]);
    }

    for (Node* node : nodes){
        if(!node->visited){
            bool result = dfs(node, nullptr);

            if(result){
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}