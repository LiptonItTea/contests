#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    
    int* num = new int[str.length()];
    for (int i = 0; i < str.length(); i++){
        num[i] = ((int) str.at(i)) - 48;
    }
    
    bool done = false;
    int* mask = new int[str.length()];
    string answer = "";
    int k = 0;
    while(!done){
        done = true;
        for (int i = 0; i < str.length(); i++){
            if(num[i] != 0){
                mask[i] = 1;
                num[i]--;
                done = false;
            }
            else
                mask[i] = 0;
        }
        if(done)
            break;
        
        k++;
        bool beautify = false;
        for (int i = 0; i < str.length(); i++){
            if(beautify || mask[i] == 1){
                beautify = true;
                answer += to_string(mask[i]);
            }
        }
        answer += " ";
    }
    cout << k << "\n" << answer;
}