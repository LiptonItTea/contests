#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        string s;
        cin >> s;

        if(s.length() % 2 == 1){
            cout << "NO\n";
            continue;
        }

        if(s[0] == ')' || s[s.length() - 1] == '('){
            cout << "NO\n";
            continue;
        }

        int lastQ = 1;
        for (int i = 0; i < s.length(); i++){
            if(s[i] == '?'){
                if(lastQ == 1){
                    s[i] = '(';
                }
                else{
                    s[i] = ')';
                }
            }
        }

        //check
        int brackets = 0;
        bool good = true;
        for (int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                brackets++;
            }
            else{
                brackets--;
            }
            if(brackets < 0){
                good = false;
                break;
            }
        }
        if(!good){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}