#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int id;
    vector<Node*> children;
};

void dfs(Node* currNode, vector<int>& order, vector<int>& first, vector<int>& height, int currHeight){
    order.push_back(currNode->id);
    first[currNode->id] = order.size() - 1;
    height[currNode->id] = currHeight;

    for (Node* nextNode : currNode->children) {
        dfs(nextNode, order, first, height, currHeight + 1);
        order.push_back(currNode->id);
    }
}

int main() {
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
    
    vector<Node*> nodes {new Node {0}};

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        string type;
        int a, b;
        cin >> type >> a >> b;
        a--; b--;

        if (type == "ADD") {
            nodes.push_back(new Node{b});
            nodes[a]->children.push_back(nodes[b]);
        }
        else {
            //GET
            vector<int> order;
            vector<int> first (nodes.size(), -1);
            vector<int> height (nodes.size(), -1); //todo shit

            dfs(nodes[0], order, first, height, 0);
            int l = min(first[a], first[b]);
            int r = max(first[a], first[b]);

            int minHeight = INT_MAX;
            int minIndex = -1;
            for (int j = l; j <= r; j++) {
                int curHeight = height[order[j]];
                int curIndex = order[j];

                if (curHeight < minHeight) {
                    minHeight = curHeight;
                    minIndex = curIndex;
                }
            }

            cout << minIndex + 1 << "\n";
        }
    }
}