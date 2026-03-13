#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> color (n);
    for (int i = 0; i < n; i++)
        cin >> color[i];

    vector<int> dp (n);
    dp[0] = 0;
    //color lastIndex
    map<int, int> dict;
    dict[color[0]] = 0;
    for (int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + 1;
        if(dict.find(color[i]) != dict.end()){
            int lastIndex = dict[color[i]];
            dp[i] = min(dp[i], dp[lastIndex] + 1);
        }
        dict[color[i]] = i;
    }

    cout << dp[n - 1];
}