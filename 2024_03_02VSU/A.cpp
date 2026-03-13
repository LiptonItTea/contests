#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int id;
    bool visited = false;
    vector<Node*> links;
    int dist;
};

int main(){
    int N, E, S, F;
    cin >> N;
    cin >> E;
    cin >> S;
    cin >> F;

    vector<Node*> nodes;
    for (int i = 0; i < N; i++){
        Node *n {};
        n->id = i;
        nodes.push_back(n);
    }

    for (int i = 0; i < E; i++){
        int n1, n2;
        cin >> n1;
        cin >> n2;
        nodes[n1 - 1]->links.push_back(nodes[n2 - 1]);
        nodes[n2 - 1]->links.push_back(nodes[n1 - 1]);
    }

    queue<Node*> queue;
    queue.push(nodes[S - 1]);
    nodes[S - 1]->dist = 0;
    while(queue.size() != 0){
        Node* curr = queue.front();
        queue.pop();
        curr->visited = true;

        cout << "WORKING WITH " << curr->id + 1 << endl;
        cout << "CURR DIST IS " << curr->dist << endl;

        for (int i = 0; i < curr->links.size(); i++){
            if(!curr->links[i]->visited){
                curr->links[i]->visited = true;
                curr->links[i]->dist = curr->dist + 1;
                queue.push(curr->links[i]);
                cout << "SET " << curr->links[i]->id + 1 << " DIST TO " << curr->links[i]->dist << endl;
                if(curr->links[i]->id == nodes[F - 1]->id){
                    cout << curr->links[i]->dist << endl;
                    goto outer;
                }
            }
        }
    }
    cout << "NOTHING FOUND ??? !!!!!!!!!!!!!!" << endl;
    outer:
        return 0;
}