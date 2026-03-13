#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
    public:
        int id;
        int color = -1;
        bool pancake;
        vector<Node*> links;
};

void connect(vector<string>& pan, vector<vector<Node*>>& nodes, int i1, int j1, int i2, int j2){
    if(pan[i1][j1] == '#')
        return;
    if(pan[i2][j2] == '#')
        return;
    
    nodes[i1][j1]->links.push_back(nodes[i2][j2]);
}

int blackNodes = 0;
int whiteNodes = 0;
int blackPancakes = 0;
int whitePancakes = 0;
void dfsColorCount(Node* curr, Node* prev){
    if(prev == nullptr)
        curr->color = 0;
    else
        curr->color = (prev->color == 0) ? 1 : 0;
    
    if(curr->color == 0){
        blackNodes++;
        if(curr->pancake)
            blackPancakes++;
    }
    else{
        whiteNodes++;
        if(curr->pancake)
            whitePancakes++;
    }

    for (Node* next : curr->links){
        if(next == prev)
            continue;
        
        if(next->color != -1)
            continue;
        
        dfsColorCount(next, curr);
    }
}

void paint(vector<string>& pan, vector<vector<Node*>>& nodes, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(pan[i][j] != '#'){
                dfsColorCount(nodes[i][j], nullptr);
                return;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> pan (n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        pan[i] = s;
    }

    int ids = 0;
    vector<vector<Node*>> nodes (n, vector<Node*> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            Node* node = new Node;

            node->id = ids++;
            node->pancake = pan[i][j] == 'P';

            nodes[i][j] = node;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(i > 0)
                connect(pan, nodes, i, j, i - 1, j);
            if(i < n - 1)
                connect(pan, nodes, i, j, i + 1, j);
            if(j > 0)
                connect(pan, nodes, i, j, i, j - 1);
            if(j < m - 1)
                connect(pan, nodes, i, j, i, j + 1);
        }
    }

    //start paint
    paint(pan, nodes, n, m);
    // cout << "Black nodes: " << blackNodes 
    //     << "\nWhite nodes: " << whiteNodes
    //     << "\nBlack pancakes: " << blackPancakes 
    //     << "\nWhite pancakes: " << whitePancakes;
    if(blackNodes + whiteNodes == 1){
        cout << "NO";
        return 0;
    }
    if(blackNodes + whiteNodes == 2){
        if(blackPancakes + whitePancakes == 2){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        return 0;
    }

    if(blackPancakes <= whiteNodes && whitePancakes <= blackNodes){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}