#include <iostream>

using namespace std;

int main(){
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    int* dp = new int[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++){
        dp[i] = INT_MIN;
        if(s[i] == 'w'){
            continue;
        }

        int grass = s[i] == '"';

        if(i - 1 == 0 || (i - 1 >= 0 && s[i - 1] != 'w' && dp[i - 1] != INT_MIN)){
            dp[i] = max(dp[i], dp[i - 1] + grass);
        }
        if(i - 3 == 0 || (i - 3 >= 0 && s[i - 3] != 'w' && dp[i - 3] != INT_MIN)){
            dp[i] = max(dp[i], dp[i - 3] + grass);
        }
        if(i - 5 == 0 || (i - 5 >= 0 && s[i - 5] != 'w' && dp[i - 5] != INT_MIN)){
            dp[i] = max(dp[i], dp[i - 5] + grass);
        }
    }

    if(dp[n - 1] == INT_MIN){
        cout << -1;
        return 0;
    }

    cout << dp[n - 1];
}