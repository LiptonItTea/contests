#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
    public:
        vector<Node*> links;
        bool visited = false;
        int evenDist = -1;
        int unevenDist = -1;
        int value = -1;
};

void msbfs(vector<Node*> starts, bool even){
    queue<Node*> nodes;
    for (Node* start : starts){
        nodes.push(start);
        start->visited = true;
    }

    int currDist = 1;
    while(!nodes.empty()){
        int currAmount = nodes.size();
        for (int i = 0; i < currAmount; i++){
            Node* curr = nodes.front(); nodes.pop();

            for (Node* next : curr->links){
                if(next->visited)
                    continue;
                
                if(even)
                    next->evenDist = currDist;
                else
                    next->unevenDist = currDist;
                
                next->visited = true;
                nodes.push(next);
            }
        }

        currDist++;
    }
}

int main() {
    // freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<Node*> nodes (n);
    for (int i = 0; i < n; i++){
        Node* node = new Node;
        nodes[i] = node;
    }

    vector<Node*> uneven;
    vector<Node*> even;
    for (int i = 0; i < n; i++){
        int value;
        cin >> value;

        nodes[i]->value = value;
        if(value % 2 == 0)
            even.push_back(nodes[i]);
        else
            uneven.push_back(nodes[i]);
        //REVERSE
        if(i - value >= 0)
            nodes[i - value]->links.push_back(nodes[i]);
        if(i + value < n)
            nodes[i + value]->links.push_back(nodes[i]);
    }

    msbfs(uneven, false);
    //clear
    for (Node* node : nodes)
        node->visited = false;
    msbfs(even, true);

    for (Node* node : nodes){
        cout << ( (node->value % 2 == 0) ? (node->unevenDist) : (node->evenDist) )<< " ";
    }
}