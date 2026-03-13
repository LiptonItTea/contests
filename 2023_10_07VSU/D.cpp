#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        string s;
        cin >> s;

        unordered_set<char> set;
        int sum = 0;
        for (int i = 0; i < s.length(); i++){
            if(set.find(s[i]) == set.end()){
                //uniqiue
                sum += 2;
                set.insert(s[i]);
            }
            else{
                sum += 1;
            }
        }
        cout << sum << "\n";
    }
}