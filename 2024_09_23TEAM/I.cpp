#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

string transform(string& s){
    if(s.size() == 1)
        return s;
    string newS;
    newS += s[0];

    string sub = s.substr(1, s.size() - 2);
    sort(sub.begin(), sub.end());
    newS += sub;

    newS += s[s.size() - 1];
    return newS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string data;
    getline(cin, data);

    vector<string> words;
    int prevIndex = 0;
    for (int i = 0; i < data.size() - 1; i++){
        if(data[i] == ' '){
            words.push_back(data.substr(prevIndex, i - prevIndex));
            prevIndex = i + 1;
        }
    }
    words.push_back(data.substr(prevIndex, data.size() - prevIndex - 1));

    int n;
    cin >> n;
    
    map<string, int> dict;
    vector<string> dictv (n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        dictv[i] = s;

        s = transform(s);
        dict[s] = i;
    }

    string result;
    for (int i = 0; i < words.size(); i++){
        string word = words[i];
        word = transform(word);

        if(dict.find(word) != dict.end()){
            int index = dict.find(word)->second;
            result += dictv[index];

            if(i != words.size() - 1)
                result += ' ';
        }
        else{
            cout << "No solution";
            return 0;
        }
    }
    result += '.';
    cout << result;
}