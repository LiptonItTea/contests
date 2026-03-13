#include <iostream>
#include <string>

using namespace std;

int counter = 0;

int recurse(string* field, int* pos, int curr){
    for (int i = 0; i < 8; i++){
        if(field[curr][i] == '*'){
            continue;
        }
        bool good = true;
        for (int j = 0; j < curr; j++){
            if(pos[j] == i || abs(curr - j) == abs(i - pos[j])){
                good = false;
                break;
            }
        }
        if(good){
            pos[curr] = i;
            if(curr + 1 < 8){
                int result = recurse(field, pos, curr + 1);
            }
            else{
                counter++;
            }
        }
    }
    return counter;
}

int main(){
    string* field = new string[8];
    for (int i = 0; i < 8; i++){
        cin >> field[i];
    }

    int* pos = new int[8];
    int result = recurse(field, pos, 0);
    cout << result;
}