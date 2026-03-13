#include <iostream>
#include <string>

using namespace std;



int main(){
    int n;
    cin >> n;

    string* cake = new string[n];
    for (int i = 0; i < n; i++)
        cin >> cake[i];
    
    int result = 0;
    for (int i = 0; i < n; i++){
        int counter = 0;
        for (int j = 0; j < n; j++){
            if(cake[i][j] == 'C'){
                counter++;
            }
        }
        result += counter * (counter - 1) / 2;
    }
    for (int i = 0; i < n; i++){
        int counter = 0;
        for (int j = 0; j < n; j++){
            if(cake[j][i] == 'C'){
                counter++;
            }
        }
        result += counter * (counter - 1) / 2;
    }

    cout << result;
}