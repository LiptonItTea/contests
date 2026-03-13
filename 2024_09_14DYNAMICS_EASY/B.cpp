#include <iostream>
#include <string>

using namespace std;

int main(){
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);

    int n;
    cin >> n;

    string field;
    cin >> field;

    int* dp = new int[n];

    dp[0] = 0;
    for (int i = 1; i < n; i++){
        dp[i] = 0;
        if(field[i] == 'w'){
            dp[i] = -1;
            continue;
        }

        int hasGrass = field[i] == '"';
        bool hasPath = false;
        if(i - 1 >= 0 && dp[i - 1] >= 0){
            dp[i] = max(dp[i], dp[i - 1]);
            hasPath = true;
        }
        if(i - 3 >= 0 && dp[i - 3] >= 0){
            dp[i] = max(dp[i], dp[i - 3]);
            hasPath = true;
        }
        if(i - 5 >= 0 && dp[i - 5] >= 0){
            dp[i] = max(dp[i], dp[i - 5]);
            hasPath = true;
        }
        if(!hasPath){
            dp[i] = -1;
            continue;
        }
        dp[i] += hasGrass;
    }

    cout << dp[n - 1];
}