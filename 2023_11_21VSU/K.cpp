#include <iostream>
#include <cstdint>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    long long minCost = INT64_MAX;
    for (int i = 0; i < n; i++){
        long long a, b;
        long long c;
        cin >> a >> b >> c;

        if(k <= a || k <= b){
            long long addLists = max(0ll, a - k);
            long long cost = (k + addLists) * c;

            minCost = min(minCost, cost);
        }
    }
    if(minCost == INT64_MAX){
        cout << "-1";
        return 0;
    }
    cout << minCost;
}