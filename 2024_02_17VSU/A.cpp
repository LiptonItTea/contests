#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    long long** ciphers = new long long*[n];
    for (int i = 0; i < n; i++){
        string data;
        cin >> data;

        ciphers[i] = new long long[k];
        for (int j = 0; j < k; j++){
            ciphers[i][j] = data[j] - 48;
        }
    }

    int* order = new int[k];
    for (int i = 0; i < k; i++){
        order[i] = i;
    }

    int minSub = INT_MAX;
    do{
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for (int i = 0; i < n; i++){
            int currNum = 0;
            for (int j = 0; j < k; j++){
                currNum += ciphers[i][order[j]] * pow(10, k - j - 1);
            }

            maxNum = max(maxNum, currNum);
            minNum = min(minNum, currNum);
        }

        minSub = min(minSub, maxNum - minNum);
    }
    while(next_permutation(order, order + k));

    cout << minSub;
}