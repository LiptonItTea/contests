#include <iostream>
#include <list>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        int* array = new int[n];
        for (int i = 0; i < n; i++){
            cin >> array[i];
        }

        if(n == 1){
            cout << 0 << "\n";
            continue;
        }

        list<pair<int, int>> swaps;
        int even = array[0] % 2;
        int farestSame = 0;
        for (int i = 1; i < n; i++){
            if(array[i] % 2 == even){
                farestSame = i;
            }
        }

        for (int i = 0; i < n; i++){
            if(i != farestSame && array[i] % 2 == even){
                array[i] = array[farestSame];
                pair<int, int> swap {i + 1, farestSame + 1};
                swaps.push_back(swap);
            }
        }

        for (int i = 1; i < n; i++){
            if(i != farestSame && array[i] % 2 != even){
                array[i] = array[0];
                pair<int, int> swap {1, i + 1};
                swaps.push_back(swap);
            }
        }

        // cout << "   ";
        // for (int i = 0; i < n; i++){
        //     cout << array[i] << " ";
        // }
        // cout << '\n';
        
        cout << swaps.size() << "\n";
        for (list<pair<int, int>>::iterator it = swaps.begin(); it != swaps.end(); it++){
            cout << "" << it->first << " " << it->second << "\n";
        }
    }
}