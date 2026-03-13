#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;
        string s;
        cin >> s;

        string newS = s;
        int i = 1;
        while(i < n){
            if(newS[i - 1] == '0' && newS[i] == '0'){
                newS.erase(i - 1, 2);
                newS.insert(i - 1, "1");
                n--;
            }
            i++;
        }
        i = 0;
        while(i < n - 2){
            if(newS[i] == '0' && newS[i + 1] == '1' && newS[i + 2] == '1'){
                for (int j = i; j >= 0; j -= 2){
                    if(newS[j] == '0' && newS[j + 1] == '1' && newS[j + 2] == '1'){
                        newS.erase(j, 3);
                        newS.insert(j, "1");
                        n -= 2;
                        i -= 2;
                    }
                }
            }
            i++;
        }
        cout << newS << "\n";
    }
}