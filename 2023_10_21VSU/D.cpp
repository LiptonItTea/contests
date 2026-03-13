#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int* array = new int[n];
    int maxCoord = INT_MIN;
    for (int i = 0; i < n; i++){
        cin >> array[i];
        maxCoord = max(maxCoord, array[i]);
    }

    unordered_map<int, bool> map;
    long long l = 0;
    long long r = maxCoord + maxCoord / 2;
    long long dist = (l + r) / 2;

    while(true){
        int cows = k;
        int prevCowCoord = INT_MIN;
        for (int i = 0; i < n; i++){
            if(prevCowCoord + dist <= array[i]){
                cows--;
                prevCowCoord = array[i];
            }
        }
        if(cows > 0){
            map[dist] = false;
        }
        else{
            map[dist] = true;
        }

        if(map.find(dist) != map.end() && map.find(dist + 1) != map.end() && map[dist] == true && map[dist + 1] == false){
            break;
        }
        if(map.find(dist - 1) != map.end() && map.find(dist) != map.end() && map[dist - 1] == true && map[dist] == false){
            dist--;
            break;
        }

        if(map[dist] == false){
            r = dist;
        }
        else{
            l = dist;
        }

        dist = (r + l) / 2;
    }
    cout << dist;
}