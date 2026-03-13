#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* p = new int[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    
    //find cycle
    int cycleNode1 = -1;
    int cycleNode2 = -1;
    for (int i = 0; i < n; i++){
        int currNode = i + 1;
        int nextNode = p[i - 1];

        if(currNode == p[nextNode - 1]){
            cycleNode1 = currNode;
            cycleNode2 = nextNode;
        }
    }
    cout << cycleNode1 << " " << cycleNode2;

    // //идея: с помощью динамики посчитать, сколько нод идут в каждую ноду, потом ликвидировать их по две
    // int* dp = new int[n];
    // for (int i = 0; i < n; i++){
    //     int currNode = p[i];
    //     int next
    // }
}