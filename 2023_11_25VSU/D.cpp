#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* array = new int[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    int* dp = new int[n];
    int maxLen = INT_MIN;
    int maxIndex = -1;
    for (int i = 0; i < n; i++){
        dp[i] = 1;

        for (int j = i - 1; j >= 0; j--){
            if(array[j] < array[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        if(maxLen < dp[i]){
            maxLen = dp[i];
            maxIndex = i;
        }
    }

    // for (int i = 0; i < n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";

    int* result = new int[maxLen];
    int currRes = maxLen - 1;
    int currLen = maxLen;
    for (int i = maxIndex; i >= 0; i--){
        if(dp[i] == currLen){
            result[currRes--] = i + 1;
            currLen--;
        }
    }

    cout << maxLen << "\n";
    for (int i = 0; i < maxLen; i++){
        cout << result[i] << " ";
    }
}