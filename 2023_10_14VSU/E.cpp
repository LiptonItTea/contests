#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    int* a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = 0;
    int r = 0;
    unordered_map<int, int> elems;
    int maxLen = INT_MIN;
    int maxL = -1;
    int maxR = -1;
    while(r < n){
        elems[a[r]]++;
        while(elems.size() > k){
            elems[a[l]]--;
            if(elems[a[l]] == 0)
                elems.erase(a[l]);
            l++;
        }
        if(maxLen < r - l + 1){
            maxLen = r - l + 1;
            maxL = l + 1;
            maxR = r + 1;
        }
        r++;
    }
    cout << maxL << " " << maxR;
}