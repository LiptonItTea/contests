#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    long long w, h, n;
    cin >> w >> h >> n;

    set<long long> hor;
    set<long long> ver;
    map<long long, int> horLens;
    map<long long, int> verLens;
    long long prevMaxWidth = w;
    long long prevMaxHeight = h;
    horLens[w]++;
    verLens[h]++;
    for (int i = 0; i < n; i++){
        char type;
        long long coord;
        cin >> type >> coord;

        if(type == 'H'){
            set<long long>::iterator down = ver.upper_bound(coord);
            int startCoord = (down == ver.begin()) ? 0 : *(--down);
            
            set<long long>::iterator up = ver.lower_bound(coord);
            int endCoord = (up == ver.end()) ? h : *up;

            ver.insert(coord);

            int prevLen = endCoord - startCoord;

            verLens[prevLen]--;
            if(verLens[prevLen] == 0){
                verLens.erase(prevLen);
            }
            verLens[coord - startCoord]++;
            verLens[endCoord - coord]++;

            prevMaxHeight = (*verLens.rbegin()).first;
        }
        else{//type=V
            set<long long>::iterator down = hor.upper_bound(coord);
            int startCoord = (down == hor.begin()) ? 0 : *(--down);

            set<long long>::iterator up = hor.upper_bound(coord);
            int endCoord = (up == hor.end()) ? w : *up;

            hor.insert(coord);
            
            int prevLen = endCoord - startCoord;

            horLens[prevLen]--;
            if(horLens[prevLen] == 0){
                horLens.erase(prevLen);
            }
            horLens[coord - startCoord]++;
            horLens[endCoord - coord]++;

            prevMaxWidth = (*horLens.rbegin()).first;
        }

        cout << prevMaxWidth * prevMaxHeight << "\n";
    }
}