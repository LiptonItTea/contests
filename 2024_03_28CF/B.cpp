#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int* data = new int[t];
    for (int i = 0; i < t; i++){
        cin >> data[i];
    }

    for (int i = 0; i < t; i++){
        int n = data[i];
        for (int y = 0; y < n * 2; y++){
            for (int x = 0; x < n * 2; x++){
                if(x % 4 < 2 && y % 4 < 2 || x % 4 >= 2 && y % 4 >= 2)
                    cout << "#";
                else
                    cout << ".";
            }
            cout << "\n";
        }
    }
}