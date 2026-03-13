#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Node {
    public:
        char lit;
        int status = 0;
        vector<Node*> outLinks;
        vector<Node*> inLinks;

        bool addOut(Node* another) {
            for (Node* some : outLinks) {
                if (some == another)
                    return false;
            }
            outLinks.push_back(another);
            return true;
        }
        bool addIn(Node* another) {
            for (Node* some : inLinks) {
                if (some == another)
                    return false;
            }
            inLinks.push_back(another);
            return true;
        }
};

bool topSort(deque<Node*>& order, Node* curr, Node* prev) {
    curr->status = 1;

    for (Node* next : curr->outLinks) {
        if (next->status == 1)
            return false;
        
        if (next->status == 2)
            continue;
        
        bool result = topSort(order, next, curr);
        if (!result) 
            return false;
    }

    curr->status = 2;
    order.push_front(curr);
    return true;
}

int main() {
    vector<Node*> nodes;
    for (int i = 0; i < 26; i++){
        Node* node = new Node;
        node->lit = (char) (97 + i);
        nodes.push_back(node);
    }

    int n;
    cin >> n;

    vector<string> words (n);
    for (int i = 0; i < n; i++){
        cin >> words[i];
    }

    for (int i = 1; i < n; i++){
        string w1 = words[i - 1];
        string w2 = words[i];

        bool found = false;
        for (int j = 0; j < min(w1.size(), w2.size()); j++){
            if (w1[j] != w2[j]){
                nodes[w1[j] - 97]->addOut(nodes[w2[j] - 97]);
                nodes[w2[j] - 97]->addIn(nodes[w1[j] - 97]);
                found = true;
                break;
            }
        }
        if (!found && w1.size() > w2.size()){
            cout << "Impossible";
            return 0;
        }
    }

    vector<char> trueOrder;
    for (Node* node : nodes) {
        if (node->status == 0 && node->inLinks.size() == 0){
            deque<Node*> order;
            bool result = topSort(order, node, nullptr);
            if (!result){
                cout << "Impossible";
                return 0;
            }

            for (Node* curr : order)
                trueOrder.push_back(curr->lit);
        }
    }

    if(trueOrder.size() != 26){
        cout << "Impossible";
        return 0;
    }
    for (char c : trueOrder)
        cout << c;
}