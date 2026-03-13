#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;

    string s;
    cin >> s;

    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++){
        int type;
        cin >> type;

        if(type == 1){
            int index;
            cin >> index;

            s[index - 1] = s[index - 1] == '0' ? '1' : '0';
        }
        else{
            int left, right;
            cin >> left >> right;

            string sub = s.substr(left - 1, right - left + 1);
            int toProcess = sub.length();
            int colorCount = 0;
            while(toProcess > 0){
                colorCount++;
                char prevChar = '.';
                for (int i = 0; i < sub.length(); i++){
                    if(prevChar == '.'){//find first non-processed
                        if(sub[i] != '.'){
                            prevChar = sub[i];
                            toProcess--;
                            sub[i] = '.';
                            continue;
                        }
                    }
                    else{
                        if(prevChar == '0' && sub[i] == '1' || prevChar == '1' && sub[i] == '0'){
                            prevChar = sub[i];
                            toProcess--;
                            sub[i] = '.';
                        }
                    }
                }
            }

            cout << colorCount << "\n";
        }
    }
}