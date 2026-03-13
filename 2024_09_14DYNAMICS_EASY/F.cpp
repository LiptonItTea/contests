#include <iostream>
#include <set>

using namespace std;

int main(){
    int curPyramid = 1;
    int curTriangle = 1;
    int curLayer = 1;

    set<int> pyrDict;
    while(curPyramid <= 300000){
        pyrDict.insert(curPyramid);
        curLayer++;
        curTriangle += curLayer;
        curPyramid += curTriangle;
    }

    int* dp = new int[300001];
    dp[0] = 0;
    for (int i = 1; i < 300001; i++){
        dp[i] = INT_MAX;
        auto it = pyrDict.upper_bound(i);
        it--;
        while(it != pyrDict.begin()){
            dp[i] = min(dp[i], dp[i - *it] + 1);
            it--;
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        cout << dp[num] << "\n";
    }
}