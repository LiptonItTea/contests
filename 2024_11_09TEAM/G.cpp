#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string data;
    cin >> data;

    set<char> exists;
    for (int i = 0; i < data.length(); i++)
        exists.insert(data[i]);
    
    set<char> onGo;
    char curChar = 'a';
    for (int i = 0; i < data.length(); i++){
        if(onGo.find(data[i]) == onGo.end()){
            onGo.insert(data[i]);
            continue;
        }
        else{
            while(exists.find(curChar) != exists.end()){
                curChar++;
            }
            if(curChar > 'z'){
                cout << "IMPOSSIBLE";
                return 0;
            }
            data[i] = curChar++;
        }
    }

    cout << data;
}