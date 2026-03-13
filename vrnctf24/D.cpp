#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

char dict[62] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

int howMany(string& origin, string& query){
    int result = 0;
    for (int i = 0; i < origin.length() - query.length() + 1; i++){
        bool good = true;
        for (int j = 0; j < query.length(); j++){
            if(origin[i + j] != query[j]){
                good = false;
                break;
            }
        }
        if(good)
            result++;
    }
    return result;
}

int charIndex(char ch){
    if(ch >= 48 && ch <= 57){
        //nums
        return ch - 48 + 52;
    }
    if(ch >= 65 && ch <= 90){
        //capslock
        return ch - 65 + 26;
    }
    ///normal
    return ch - 97;
}

void findResults(int arr[62][62], string& curr, vector<string>& results, int originIndex, int maxe){
    for (int i = 0; i < 62; i++){
        if(arr[originIndex][i] == maxe){
            curr += dict[i];
            //todo copy
            results.push_back(curr);
            findResults(arr, curr, results, i, maxe);
        }
    }
    if(curr.length() > 0)
        curr.pop_back();
}

int main(){
    string data;
    cin >> data;

    unordered_map<char, int> map;
    for (int i = 0; i < data.length(); i++){
        map[data[i]]++;
    }
    // for (auto it = map.begin(); it != map.end(); it++){
    //     auto pair = *it;
    //     cout << pair.first << ": " << pair.second << "\n";
    // }
    int pairarr[62][62];
    for (int i = 0; i < 62; i++){
        for (int j = 0; j < 62; j++){
            string q = string();
            q += dict[i];
            q += dict[j];
            pairarr[i][j] = howMany(data, q);
            // cout << pairarr[i][j] << " ";
        }
        // cout << "\n";
    }

    int maxe = 0;
    for (auto it = map.begin(); it != map.end(); it++){
        auto pair = *it;
        maxe = max(maxe, pair.second);
    }
    vector<string> results;
    for (auto it = map.begin(); it != map.end(); it++){
        auto pair = *it;
        char currch = pair.first;
        int curre = pair.second;
        if(curre == maxe){
            //found first max char
            //next found its max pair
            int chIndex = charIndex(currch);
            string path = string() + dict[chIndex];
            results.push_back(path);

            findResults(pairarr, path, results, chIndex, maxe);
        }
    }
    cout << results.size() << "\n";
    for (string s : results){
        cout << s << "\n";
    }
}