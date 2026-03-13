#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

bool cmp(int* sock1, int* sock2){
    if(sock1[0] != sock2[0])
        return sock1[0] < sock2[0];
    
    return sock1[1] < sock2[1];
}

int main () {
    int n;
    cin >> n;

    int** array = new int*[n];
    unordered_map<int, int> counter;
    for (int i = 0; i < n; i++){
        int s, h;
        cin >> s >> h;

        array[i] = new int[3];
        array[i][0] = s;
        array[i][1] = h;
        array[i][2] = i + 1;

        counter[s]++;
    }
    for (auto it = counter.begin(); it != counter.end(); it++){
        if(it->second < 2){
            cout << -1;
            return 0;
        }
    }

    sort(array, array + n, cmp);

    int i = 0;
    bool found = true;
    int prevSize = array[i][0];
    list<pair<int, int>> result;
    while (i < n - 1){
        if(found){
            result.push_back({array[i][2], array[i + 1][2]});
            found = false;
        }

        if(!found){
            i++;
            if(array[i][0] != prevSize){
                found = true;
                prevSize = array[i][0];
            }
        }
    }

    cout << result.size() << "\n";
    for (auto it = result.begin(); it != result.end(); it++)
        cout << it->first << " " << it->second << "\n";
}