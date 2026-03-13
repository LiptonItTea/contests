#include <iostream>
#include <set>

using namespace std;

int binary_search(int* array, int n, int value){
    int l = 1;
    int r = n;
    int m = (l + r) / 2;

    while(true){
        if(array[m - 1] < value && value <= array[m]){
            return m;
        }

        if(value < array[m])
            r = m;
        else
            l = m;

        m = (l + r) / 2;
    }
}

int main(){
    int n;
    cin >> n;

    int* array = new int[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    int* dp = new int[n + 1];
    dp[0] = INT_MIN;
    for (int i = 1; i < n + 1; i++){
        dp[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++){
        int j = binary_search(dp, n + 1, array[i]);

        if(dp[j - 1] < array[i] && array[i] < dp[j]){
            dp[j] = array[i];
        }
    }

    int counter = 0;
    for (int i = 1; i < n+1; i++){
        if(dp[i] == INT_MAX){
            break;
        }
        counter++;
    }

    cout << counter;
}