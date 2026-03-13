#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int counter = 1;
    for (int i = 1; i < s.length(); i++){
        if(s[i] != s[i - 1])
            counter++;
    }

    cout << counter;
}