#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    map<char, int> amounts;
    for (char c = 'a'; c <= 'z'; c++){
        int amount;
        cin >> amount;

        amounts[c] = amount;
    }

    int maxLen = 0;
    int l = 0;
    int r = 0;
    while(r < n){
        if(amounts[s[r]] > 0){
            amounts[s[r]]--;
            r++;
        }
        else{
            maxLen = max(maxLen, r - l);
            amounts[s[l]]++;
            l++;
        }
    }
    maxLen = max(maxLen, r - l);

    cout << maxLen;
}