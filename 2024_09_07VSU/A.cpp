#include <iostream>
#include <string>

using namespace std;

int main () {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        string str;
        cin >> str;

        bool found = false;
        for (int i = 1; i < str.length(); i++){
            if(str[i - 1] != str[i]){
                found = true;
                cout << i << " " << i + 1 << "\n";
                break;
            }
        }
        if(!found)
            cout << "-1 -1\n";
    }
}