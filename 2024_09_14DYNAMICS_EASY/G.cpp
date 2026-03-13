#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int dp = -1;
        vector<Node*> inLinks;
        vector<Node*> outLinks;
};

void dfs(Node* curr, Node* prev, int depth){
    curr->dp = depth;

    for (Node* next : curr->outLinks){
        if(next == prev)
            continue;
        
        if(next->dp > curr->dp){
            continue;
        }

        dfs(next, curr, depth + 1);
    }
}

int main() {
    freopen("longpath.in", "r", stdin);
    freopen("longpath.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<Node*> nodes; nodes.reserve(n);
    for (int i = 0; i < n; i++){
        Node* node = new Node;
        nodes.push_back(node);
    }

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        nodes[a - 1]->outLinks.push_back(nodes[b - 1]);
        nodes[b - 1]->inLinks.push_back(nodes[a - 1]);
    }

    for (Node* node : nodes){
        if(node->inLinks.size() == 0){
            dfs(node, nullptr, 0);
        }
    }

    int maxLen = INT_MIN;
    for (Node* node : nodes)
        maxLen = max(maxLen, node->dp);
    cout << maxLen;
}