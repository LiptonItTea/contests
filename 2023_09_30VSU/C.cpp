#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> o1, pair<string, int> o2){
    return o1.second > o2.second;
}

int main(){
    unordered_map<string, int> mapper;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        string user;
        cin >> user;

        mapper[user] = i;
    }

    int size = mapper.size();
    pair<string, int>* array = new pair<string, int>[size];
    int i = 0;
    for (unordered_map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++){
        array[i++] = (*it);
    }
    sort(array, array + size, compare);
    for (int i = 0; i < size; i++){
        cout << array[i].first << "\n";
    }
}