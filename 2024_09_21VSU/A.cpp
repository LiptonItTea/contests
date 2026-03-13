#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Node {
    public:
        list<Node*> links;
        bool visited = false;
        int dist = 0;
};

void bfs(Node* start, Node* end){
    queue<Node*> nodes;
    nodes.push(start);

    Node* curr;
    int counter = 1;
    while(!nodes.empty()){
        int epoch = nodes.size();
        for (int _ = 0; _ < epoch; _++){
            curr = nodes.front();
            nodes.pop();

            for (Node* next : curr->links){
                if(next->visited)
                    continue;
                next->dist = counter;

                if(next == end){
                    return;
                }
                
                next->visited = true;
                nodes.push(next);
            }
        }
        counter++;
    }
}

int main() {
    int n, e, s, f;
    cin >> n >> e >> s >> f;

    vector<Node*> nodes; nodes.reserve(n);
    for (int i = 0; i < n; i++){
        Node* node = new Node;
        nodes.push_back(node);
    }

    for (int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;

        nodes[u - 1]->links.push_back(nodes[v - 1]);
        nodes[v - 1]->links.push_back(nodes[u - 1]);
    }

    bfs(nodes[s - 1], nodes[f - 1]);
    cout << nodes[f - 1]->dist;
}