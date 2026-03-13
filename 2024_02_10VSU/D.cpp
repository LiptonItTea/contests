#include <iostream>
#include <list>
#include <math.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        long long w;
        cin >> w;

        int* array = new int[n];
        bool preSol = false;
        for (int i = 0; i < n; i++){
            cin >> array[i];
        }

        for (int i = 0; i < n; i++){
            if(ceil(w / 2.0) <= array[i] && array[i] <= w){
                cout << "" << 1 << "\n" << i + 1 << "\n";
                preSol = true;
                break;
            }
        }
        if(preSol)
            continue;
        
        //after pre solution we have items > w (bad) and items < w/2 (not bad, not good)
        //sum items < w/2 
        bool sol = false;
        long long currMass = 0;
        list<int> indexes;
        for (int i = 0; i < n; i++){
            if(array[i] > w){
                continue;
            }
            
            currMass += array[i];
            indexes.push_back(i);
            if(currMass >= ceil(w / 2.0)){
                cout << "" << indexes.size() << "\n";
                for (auto it = indexes.begin(); it != indexes.end(); it++){
                    cout << (*it) + 1 << ' ';
                }
                cout << "\n";
                sol = true;
            }
            if(sol){
                break;
            }
        }
        if(!sol)
            cout << "-1\n";
    }
}