#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int in = -1;
        int out = -1;
        Node* parent;
        vector<Node*> children;
};

int counter = 0;
void dfs(Node* curr, Node* prev){
    curr->in = counter++;
    
    for (Node* child : curr->children){
        if(child == prev)
            continue;
        
        dfs(child, prev);
    }
    curr->out = counter++;
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes (n);
    for (int i = 0; i < n; i++){
        Node* node = new Node;
        nodes[i] = node;
    }
    
    Node* root;
    for (int i = 0; i < n; i++){
        int j;
        cin >> j;

        if(j == 0){
            root = nodes[i];
            continue;
        }
        nodes[i]->parent = nodes[j - 1];
        nodes[j - 1]->children.push_back(nodes[i]);
    }

    dfs(root, nullptr);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        Node* nodea = nodes[a - 1];
        Node* nodeb = nodes[b - 1];
        
        if(nodea->in < nodeb->in && nodea->out > nodeb->out){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
}