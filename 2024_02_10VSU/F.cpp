#include <iostream>
#include <string>

using namespace std;

int crawl(string& s, int k, int n, char ch){
    int maxLen = 0;

    int l = 0;
    int r = -1;
    //find first a
    for (int i = 0; i < n; i++){
        if(s[i] == ch){
            l = max(0, i - k);
            r = i;
            break;
        }
    }
    
    if(r == -1){
        return 0;
    }

    int currK = k - (r - l);
    maxLen = max(maxLen, r - l + 1);
    //a
    while (r < n){
        if(s[r] == ch){
            r++;
        }
        else if(currK > 0){
            r++;
            currK--;
        }
        else{
            if(s[l] != ch){
                currK++;
            }
            l++;
        }
        maxLen = max(maxLen, r - l);
    }
    return maxLen;
}

int main(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int maxLen = crawl(s, k, n, 'a');
    maxLen = max(maxLen, crawl(s, k, n, 'b'));
    cout << maxLen;
}