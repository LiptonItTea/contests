#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node {
    public:
        long long id;
        long long ambassAmount = 0;

        long long color = -1;

        vector<Node*> links;

        Node (long long id) {
            this->id = id;
        }
};

class DSU {
    public:
        long long n;
        vector<long long> parents;

        DSU (long long n){
            this->n = n;
            parents.reserve(n);
            for (long long i = 0; i < n; i++)
                parents.push_back(i);
        }

        long long getParent(long long u){
            return (parents[u] == u) ? (u) : (parents[u] = getParent(parents[u]));
        }

        void unionParents(long long u, long long v){
            long long parentU = getParent(u);
            long long parentV = getParent(v);

            if(parentU == parentV){
                return;
            }

            parents[parentU] = parentV;
        }
};

//true if uneven cycle is found
bool dfsColorize(Node* curr, Node* prev){
    if(prev != nullptr){
        if(prev->color == 0){
            curr->color = 1;
        }
        else{
            curr->color = 0;
        }
    }
    else{
        curr->color = 0;
    }

    for (Node* next : curr->links){
        if(next == prev){
            continue;
        }

        if(next->color != -1){
            if(curr->color == next->color){
                return true;
            }
            continue;
        }

        bool result = dfsColorize(next, curr);
        if(result)
            return true;
    }

    return false;
}

int main(){
    long long n, m;
    cin >> n >> m;

    vector<Node*> nodes;
    nodes.reserve(n);
    for (long long i = 0; i < n; i++){
        Node* node = new Node(i);
        nodes.push_back(node);
    }

    DSU dsu (n);
    for (long long i = 0; i < m; i++){
        long long u, v;
        cin >> u >> v;

        nodes[u - 1]->links.push_back(nodes[v - 1]);
        nodes[v - 1]->links.push_back(nodes[u - 1]);
        dsu.unionParents(u - 1, v - 1);
    }
    //map components
    map<long long, vector<Node*>> componentMap;
    for (long long i = 0; i < n; i++){
        long long nodeId = i;
        long long parentId = dsu.getParent(i);

        componentMap[parentId].push_back(nodes[nodeId]);
    }

    for (long long i = 0; i < n; i++){
        long long ambassAmount;
        cin >> ambassAmount;

        nodes[i]->ambassAmount = ambassAmount;
    }

    //phase 1 - iterate over each component, count sum and check validity
    for (auto it = componentMap.begin(); it != componentMap.end(); it++){
        long long parentId = it->first;
        vector<Node*> component = it->second;

        long long ambassCount = 0;
        for (Node* node : component){
            ambassCount += node->ambassAmount;
        }

        if(component.size() != ambassCount){
            cout << "Fake";
            return 0;
        }
    }

    //phase 2 - colorize each component. If uneven cylce is found, ignore this component
    long long weekEven = -1;
    for (auto it = componentMap.begin(); it != componentMap.end(); it++){
        long long parentId = it->first;
        vector<Node*> component = it->second;

        bool result = dfsColorize(component[0], nullptr);
        if(result) //found uneven cycle
            continue;
        
        //two-colored graph
        //phase 3 - count ambasses in black and white nodes, count black and white nodes and compare
        long long blackAmbassesCounter = 0;
        long long whiteAmbassesCounter = 0;
        long long blackNodes = 0;
        long long whiteNodes = 0;
        for (Node* node : component){
            if(node->color == 0){//black
                blackNodes++;
                blackAmbassesCounter += node->ambassAmount;
            }
            else{//white
                whiteNodes++;
                whiteAmbassesCounter += node->ambassAmount;
            }
        }

        bool even = blackAmbassesCounter == blackNodes && whiteAmbassesCounter == whiteNodes;
        bool uneven = blackAmbassesCounter == whiteNodes && whiteAmbassesCounter == blackNodes;
        if(even || uneven){
            if(blackNodes != whiteNodes){
                if(weekEven == -1){
                    if(even)
                        weekEven = 0;
                    else
                        weekEven = 1;
                }
                else{
                    if(weekEven == 0 && even || weekEven == 1 && uneven){
                        //ok
                    }
                    else{
                        cout << "Fake";
                        return 0;
                    }
                }
            }
        }
        else{
            cout << "Fake";
            return 0;
        }
        // if(blackNodes == whiteNodes && (even || uneven)){
        //     continue;
        // }

        // //phase 4 - get even of week
        // if(weekEven == -1){
        //     if(even)
        //         weekEven = 0;
        //     else
        //         weekEven = 1;
        // }
        // else{
        //     if(weekEven == 0 && even || weekEven == 1 && uneven){
        //         //ok
        //     }
        //     else{
        //         cout << "Fake";
        //         return 0;
        //     }
        // }
    }

    cout << "Realistic";
}