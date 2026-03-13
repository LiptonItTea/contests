#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_map<string, string> map;
    unordered_set<string> set;

    for (int i = 0; i < n; i++){
        string first, second;
        cin >> first >> second;

        map[first] = second;
        set.insert(second);
    }
    unordered_map<string, string> original;
    for (unordered_map<string, string>::iterator it = map.begin(); it != map.end(); it++){
        string first = it->first;
        string second = it->second;

        //original
        if(set.find(first) == set.end()){
            string curr = second;
            while(true){
                original[first] = curr;
                if(map.find(curr) == map.end())
                    break;
                curr = map[curr];
            }
        }
    }
    cout << original.size() << "\n";
    for (unordered_map<string, string>::iterator it = original.begin(); it != original.end(); it++){
        cout << it->first << " " << it->second << "\n";
    }
}