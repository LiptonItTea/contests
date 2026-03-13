#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareSecond(pair<int, int>& p1, pair<int, int>& p2){
    return p1.second < p2.second;
}

void skipVoid(vector<pair<int, int>>::iterator& it){
    while(it->first == -1){
        it++;
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    //       lesson, lastTime
    vector<pair<int, int>> times (k + 1, {-1, -1});
    for (int i = 0; i < n; i++){
        int lesson;
        cin >> lesson;

        times[lesson] = {lesson, i};
    }
    sort(times.begin(), times.end(), compareSecond);

    auto it = times.begin();
    skipVoid(it);
    int lesson = it->first;
    int lastTime = it->second;
    for (int i = 0; i < n; i++){
        if(i == lastTime){
            cout << lesson << " ";
            it++;
            skipVoid(it);
            lesson = it->first;
            lastTime = it->second;
        }
        else{
            cout << "0 ";
        }
    }
}