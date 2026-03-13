#include <iostream>
#include <vector>

using namespace std;

int main(){
    int s, n;
    cin >> s >> n;  

    int* w = new int[n];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    
    vector<bool> dp (s + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++){
        int currW = w[i];

        for (int j = s; j >= currW; j--){
            dp[j] = dp[j] || dp[j - currW];
        }
    }

    for (int i = s; i >= 0; i--){
        if(dp[i]){
            cout << i;
            return 0;
        }
    }
}