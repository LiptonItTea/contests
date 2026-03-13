#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        int mainSwap = n / 2;
        int restSwap = n % 2;

        cout << mainSwap + restSwap << "\n";
        for (int i = 0; i < mainSwap; i++){
            cout << "" << i * 3 + 1 << " " << (n * 3 - 1) - (i * 3) + 1 << "\n";
        }
        if(restSwap){
            cout << "" << mainSwap * 3 + 1 << " " << mainSwap * 3 + 2 + 1 << "\n";
        }
    }
}