#include <iostream>
#include <string>

using namespace std;

int main () {
    string data;
    cin >> data;

    int open = 0;
    for (int i = 0; i < data.length(); i++){
        if(data[i] == '(')
            open++;
        else
            open--;
        
        if(open < 0){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << data << "";
    for (int i = 0; i < open; i++)
        cout << ")";
}