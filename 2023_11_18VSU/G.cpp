#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isLexi(string s1, string s2){
    for (int i = 0; i < s1.length(); i++){
        if(s1[i] < s2[i])
            return true;
        else if(s1[i] > s2[i])
            return false;
    }
    return s1.length() <= s2.length();
}

int main(){
    long long n;
    cin >> n;

    long long* c = new long long[n];
    for (long long i = 0; i < n; i++){
        cin >> c[i];
    }

    string** data = new string*[n];
    for (long long i = 0; i < n; i++){
        data[i] = new string[2];
        cin >> data[i][0];
        string s = data[i][0];
        reverse(s.begin(), s.end());
        data[i][1] = s;
    }

    long long** dp = new long long*[n];
    for (long long i = 0; i < n; i++){
        dp[i] = new long long[2];
        dp[i][0] = LONG_MAX;
        dp[i][1] = LONG_MAX;
    }
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (long long i = 1; i < n; i++){
        for (long long j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                if(data[i][j] >= data[i - 1][k]){
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * c[i]);
                }
            }
        }
    }
    if(min(dp[n - 1][0], dp[n - 1][1]) == LONG_MAX){
        cout << -1;
    }
    else{
        cout << min(dp[n - 1][0], dp[n - 1][1]);
    }
}