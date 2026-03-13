#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    long long l = 1;
    long long r = 2;
    long long h;
    map<long long, bool> dict;
    //find bounds
    while(true){
        h = (l + r) / 2ll;
        cout << h << endl;

        string result;
        cin >> result;
        if(result == "fail")
            return 0;
        
        if(result == "wet"){
            l = h;
            r *= 2ll;
            dict[h] = false;
        }
        else{
            r = h;
            dict[h] = true;
            break;
        }
    }
    while(true){
        h = (l + r) / 2ll;
        cout << h << endl;
        string result;
        cin >> result;
        if(result == "fail")
            return 0;

        if(result == "ok"){
            dict[h] = true;
        }
        else{
            dict[h] = false;
        }

        if(dict.find(h - 1ll) != dict.end() && dict[h - 1ll] == false && dict[h] == true){
            break;
        }
        if(dict.find(h + 1ll) != dict.end() && dict[h] == false && dict[h + 1ll] == true){
            h += 1ll;
            break;
        }

        if(result == "ok"){
            r = h;
        }
        else{
            l = h;
        }
    }

    cout << "! " << h;
}