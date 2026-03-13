#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class CompareStrings {
    public:
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) const {
            return p1.first < p2.first;
        }
};

int main() {
    int n;
    cin >> n;

    set<pair<string, int>, CompareStrings> strs;
    vector<string> vec; vec.reserve(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        strs.insert({s, i});
        vec.push_back(s);
    }

    for (int k = 0; k < n; k++){
        string s = vec[k];
        int index = k;
        strs.erase({s, index});
        //todo check s == otherS
        if(strs.find({s, -1}) != strs.end()){
            cout << "YES\n";
            cout << index + 1 << " " << strs.find({s, -1})->second + 1;
            return 0;
        }
        for (int i = (s.length() - 1) / 2; i < s.length() - 1; i++){
            string afterMid = s.substr(i + 1);

            bool bad = false;
            for (int j = 0; j < afterMid.length(); j++){
                if(s[j] != afterMid[j]){
                    bad = true;
                    break;
                }
            }
            if(bad)
                continue;

            string otherS = s.substr(afterMid.length(), s.length() - 2 * afterMid.length());
            if(strs.find({otherS, -1}) != strs.end()){
                cout << "YES\n";
                cout << index + 1 << " " << strs.find({otherS, -1})->second + 1;
                return 0;
            }
        }
        strs.insert({s, index});
    }

    cout << "NO";
}