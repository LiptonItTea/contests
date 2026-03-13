#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int* query = new int[t];
    int maxQ = 0;
    for (int i = 0; i < t; i++){
        cin >> query[i];
        maxQ = max(maxQ, query[i]);
    }

    int* calc = new int[maxQ];
    int shift = 1;
    for (int i = 0; i < maxQ; i++){
        while(shift % 3 == 0 || shift % 10 == 3)
            shift++;
        
        calc[i] = shift;
        shift++;
    }

    for (int i = 0; i < t; i++){
        cout << calc[query[i] - 1] << "\n";
    }
}