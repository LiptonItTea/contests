#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Node {
    public:
        list<Node*> links;
        int in = -1;
        int out = -1;
};

int counter = 0;
void dfs(Node* curr){
    curr->in = counter;

    for (Node* next : curr->links){
        counter++;
        dfs(next);
    }
    counter++;
    curr->out = counter;
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes; nodes.reserve(n);
    for (int i = 0; i < n; i++){
        Node* node = new Node;
        nodes.push_back(node);
    }
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;

        if(v == 0)
            continue;

        nodes[v - 1]->links.push_back(nodes[i]);
    }

    dfs(nodes[0]);
    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        Node* na = nodes[a - 1];
        Node* nb = nodes[b - 1];

        if(na->in <= nb->in && nb->out <= na->out){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
}