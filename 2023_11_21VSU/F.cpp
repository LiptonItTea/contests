#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int k;
    cin >> k;

    char dict[] = {'a', 'e', 'i', 'o', 'u'};

    bool prevGlas = false;
    for (int i = 0; i < 5; i++){
        if(s[0] == dict[i]){
            prevGlas = true;
            break;
        }
    }

    //find k-len repeats
    int l = 0;
    int currK = k - 1;
    list<pair<int, int>> repeats;
    for (int r = 1; r < s.length(); r++){
        bool glas = false;
        for (int i = 0; i < 5; i++){
            if(s[r] == dict[i]){
                glas = true;
                break;
            }
        }

        if(prevGlas == glas){
            currK--;
        }
        else{
            l = r;
            currK = k - 1;
        }

        if(currK == 0){
            pair<int, int> rep {l, r};
            repeats.push_back(rep);

            currK = 1;
            l++;
        }
        prevGlas = glas;
    }

    int lastL = 0;
    int maxLen = INT_MIN;
    for (list<pair<int, int>>::iterator it = repeats.begin(); it != repeats.end(); it++){
        maxLen = max(maxLen, it->second - lastL);
        lastL = it->first + 1;
    }
    maxLen = max(maxLen, (int) s.length() - lastL);
    cout << maxLen;
}