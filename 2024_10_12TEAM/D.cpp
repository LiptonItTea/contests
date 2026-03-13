#include <iostream>
#include <queue>
#include <set>

using namespace std;

class Node {
    public:
        int id;
        int droids;
        int curClones;
        vector<Node*> links;

        bool operator()(const Node* n1, const Node* n2) const {
            if(n1->curClones != n2->curClones)
                return n1->curClones > n2->curClones;
            return n1->id > n2->id;
        }
};

// class CompareNodes {
//     public:
//         bool operator()(const pair<int, Node*>& p1, const pair<int, Node*>& p2){
//             if(p1.first != p2.first)
//                 return p1.first > p2.first;
//             return p1.second->id > p2.second->id;
//         }
// };

void dijkstra(vector<Node*>& nodes, int startIndex, int endIndex){
    Node* start = nodes[startIndex];
    Node* end = nodes[endIndex];

    set<Node*, Node> queue;
    queue.insert(start);
    for (int i = 1; i < nodes.size(); i++)
        queue.insert(nodes[i]);
    
    while (queue.size() != 0){
        Node* curr = *queue.begin();
        if(curr == end){
            break;
        }

        for (Node* next : curr->links){
            if(queue.find(next) == queue.end())
                continue;
            
            int plannedCurClones = curr->curClones;
            if(curr->curClones <= next->droids)
                plannedCurClones = plannedCurClones / 2;
            
            if(plannedCurClones > next->curClones){
                queue.erase(next);
                next->curClones = plannedCurClones;
                queue.insert(next);
            }
        }
        queue.erase(curr);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Node*> nodes; nodes.reserve(n);
    for (int i = 0; i < n; i++){
        Node* node = new Node;
        node->id = i;
        node->curClones = 0;

        nodes.push_back(node);
    }

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        nodes[u - 1]->links.push_back(nodes[v - 1]);
        nodes[v - 1]->links.push_back(nodes[u - 1]);
    }

    int x;
    cin >> x;
    nodes[0]->curClones = x;

    for (int i = 0; i < n; i++){
        int amount;
        cin >> amount;

        nodes[i]->droids = amount;
    }
    if(nodes[0]->curClones <= nodes[0]->droids)
        nodes[0]->curClones /= 2;

    dijkstra(nodes, 0, n - 1);
    cout << nodes[n - 1]->curClones;
}