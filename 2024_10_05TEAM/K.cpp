#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int counter = 0;
    for (int i = 3; i < s.length(); i++){
        if(s[i - 3] == 'k' && s[i - 2] == 'i' && s[i - 1] == 'c' && s[i] == 'k'){
            counter++;
        }
    }

    cout << counter;
}