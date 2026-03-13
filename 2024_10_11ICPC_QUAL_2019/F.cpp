#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

void toListString(list<int>& l, string& num){
    for (int i = 0; i < num.size(); i++){
        l.push_back(num[i] - 48);
    }
}

void toList(list<int>& l, long long num){
    while(num > 0){
        l.push_front(num % 10);
        num /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int temp [27];
    temp[0] = 2;
    temp[1] = 3;
    temp[2] = 5;
    temp[3] = 7;
    temp[4] = 11;
    temp[5] = 19;
    temp[6] = 41;
    temp[7] = 61;
    temp[8] = 89;
    temp[9] = 409;
    temp[10] = 449;
    temp[11] = 499;
    temp[12] = 881;
    temp[13] = 991;
    temp[14] = 6469;
    temp[15] = 6949;
    temp[16] = 9001;
    temp[17] = 9049;
    temp[18] = 9649;
    temp[19] = 9949;
    temp[20] = 60649;
    temp[21] = 666649;
    temp[22] = 946669;
    temp[23] = 60000049;
    temp[24] = 66000049;
    temp[25] = 66600049;

    string n;
    cin >> n;
    list<int> num;
    toListString(num, n);

    vector<pair<int, vector<int>>> dict;
    for (int i = 0; i < 26; i++){
        list<int> l;
        toList(l, temp[i]);
        vector<int> v; v.reserve(l.size());
        for (auto it = l.begin(); it != l.end(); it++)
            v.push_back(*it);

        pair<int, vector<int>> p {0, v};
        dict.push_back(p);
    }

    for (auto it = num.begin(); it != num.end(); it++){
        for (int j = 0; j < dict.size(); j++){
            if(dict[j].first < dict[j].second.size() && (*it) == dict[j].second[dict[j].first]){
                dict[j].first++;
            }
        }
    }

    for (int j = dict.size() - 1; j >= 0; j--){
        if(dict[j].first == dict[j].second.size()){
            vector<int> dictNum = dict[j].second;

            for (int i = 0; i < dictNum.size(); i++)
                cout << dictNum[i];
            cout << '\n';

            if(dictNum.size() == num.size()){
                cout << -1;
                return 0;
            }          

            int p = 0;
            int i = 0;
            for (auto it = num.begin(); it != num.end(); it++){
                if(p == dictNum.size()){
                    cout << i << " ";
                    i++;
                    continue;
                }

                if(*it != dictNum[p]){
                    cout << i << " ";
                }
                else
                    p++;
                i++;
            }

            return 0;
        }
    }

    cout << -1;
}