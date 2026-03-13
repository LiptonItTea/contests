#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>

using namespace std;

struct Node {
    int id;
    bool visited = false;
    vector<Node*> connections;
};

bool dfs(Node* currNode, Node* prevNode, list<Node*>* cycle){
    currNode->visited = true;
    for (Node* nextNode : currNode->connections){
        if(nextNode != prevNode){
            cycle->push_back(nextNode);
            if (nextNode->visited == true){
                //find first encounter of this vertex
                for (list<Node*>::iterator it = cycle->begin(); it != cycle->end(); it++){
                    Node* n = *it;
                    if(n->id == nextNode->id){
                        cycle->erase(cycle->begin(), ++it);
                        return true;
                    }
                }
            }
            else{
                bool result = dfs(nextNode, currNode, cycle);
                if(result)
                    return true;
            }
            cycle->pop_back();
        }
    }
    currNode->visited = false;
    return false;
}

int main(){
    int n;
    cin >> n;

    vector<Node*> nodes;
    nodes.reserve(n);
    for (int i = 0; i < n; i++){
        Node* n = new Node;
        n->id = i;
        nodes.push_back(n);
    }

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        nodes[a - 1]->connections.push_back(nodes[b - 1]);
        nodes[b - 1]->connections.push_back(nodes[a - 1]);
    }

    list<Node*>* cycle = new list<Node*>;
    cycle->push_back(nodes[0]);
    dfs(nodes[0], nullptr, cycle);

    set<pair<int, int>> edges;
    Node* prevNode = nullptr;
    for (list<Node*>::iterator it = cycle->begin(); it != cycle->end(); it++){
        if(prevNode == nullptr){
            prevNode = *it;
            continue;
        }
        Node* currNode = *it;
        
        int first = min(prevNode->id, currNode->id);
        int second = max(prevNode->id, currNode->id);
        pair<int, int> p {first + 1, second + 1};
        edges.insert(p);
        prevNode = currNode;
    }
    //interprete prevNode as lastNode
    int first = min(prevNode->id, (*cycle->begin())->id);
    int second = max(prevNode->id, (*cycle->begin())->id);
    pair<int, int> p {first + 1, second + 1};
    edges.insert(p);
    
    cout << edges.size() << "\n";
    for (set<pair<int, int>>::iterator it = edges.begin(); it != edges.end(); it++){
        cout << it->first << " " << it->second << "\n";
    }
}