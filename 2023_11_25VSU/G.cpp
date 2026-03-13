#include <iostream>

using namespace std;

int binary_search(int* array, int n, int value){
    int l = 0;
    int r = n;
    int m = (r + l) / 2;

    while(true){
        // cout << (m > 0) << " " << (array[m - 1] <= value) << " " << (value < array[m]) << "\n";
        if(m > 0 && array[m - 1] <= value && value < array[m])
            return m;
        
        if(m < n - 1 && array[m] <= value && value < array[m + 1]){
            return m + 1;
        }

        if(value < array[m])
            r = m;
        else
            l = m;
        
        m = (r + l) / 2;
    }
}

int main(){
    int t;
    cin >> t;

    int* pyramid = new int[300000];
    int currK = 1;
    pyramid[0] = 1;

    int* dp = new int[300000];
    dp[0] = 0;
    int currDp = 0;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        while (n >= pyramid[currK - 1]){
            currK++;
            pyramid[currK - 1] = currK * (currK + 1) * (currK + 2) / 6;
        }

        //DEBUG
        // for (int i = 0; i < currK; i++){
        //     cout << pyramid[i] << " ";
        // }
        // cout << "\n";
        
        int startIndex = binary_search(pyramid, currK, currDp + 1) - 1;
        for (int i = currDp + 1; i <= n; i++){
            if(i >= pyramid[startIndex + 1]){
                startIndex++;
            }
            int minPyramids = INT_MAX;
            for (int j = startIndex; j >= 0; j--){
                minPyramids = min(minPyramids, dp[i - pyramid[j]] + 1);
            }
            dp[i] = minPyramids;
        }
        currDp = n;

        // for (int i = 1; i <= currDp; i++){
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";

        cout << dp[n] << "\n";
    }
}