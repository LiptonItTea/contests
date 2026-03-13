#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int k;
    cin >> k;

    set<int> setDivs;
    for (int i = 2; i * i <= k; i++){
        if(k % i == 0){
            setDivs.insert(i);
            setDivs.insert(k / i);
        }
    }
    setDivs.insert(k);

    vector<int> divs (setDivs.begin(), setDivs.end());

    vector<int> dp (k + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= k; i++){
        for (int k = 0; k < divs.size(); k++){
            int j = divs[k];
            if(i % j == 0)
                dp[i] += dp[i / j];
        }
    }
    cout << dp[k];
}