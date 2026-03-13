#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>

using namespace std;

class Node {
    public:
        int id;
        int k;

        vector<Node*> links;
        
        // iter  c
        map<int, long long> history;
};

int solve(Node* start, long long c){
    Node* curr = start;

    int counter = 0;
    while(true){
        long long m = curr->links.size();

        if(curr->history.size()){
            for (auto it = curr->history.begin(); it != curr->history.end(); it++){
                int currCounter = it->first;
                long long currC = it->second;

                if(c % m == currC % m){
                    return counter - currCounter;
                }
            }
        }

        curr->history[counter++] = c;
        c += (long long) curr->k;
        
        long long index = c % m;
        if(index < 0)
            index += m;
        curr = curr->links[index];
    }
}

int main() {
    int n;
    cin >> n;
    vector<Node*> nodes;
    nodes.reserve(n);
    for (int i = 0; i < n; i++){
        Node* node = new Node;
        node->id = i + 1;

        nodes.push_back(node);
    }

    for (int i = 0; i < n; i++){
        cin >> nodes[i]->k;
    }
    
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;

        for (int j = 0; j < m; j++){
            int e;
            cin >> e;

            nodes[i]->links.push_back(nodes[e - 1]);
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;

        int result = solve(nodes[x - 1], y);
        cout << "   " << result << "\n";
        for (Node* node : nodes)
            node->history.clear();
    }
}