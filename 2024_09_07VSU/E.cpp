#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main () {
    long long n, k, x;
    cin >> n >> k >> x;

    if(n == 1){
        cout << 1;
        return 0;
    }

    long long* array = new long long[n];
    for (long long i = 0; i < n; i++)
        cin >> array[i];
    //O(nlogn)
    sort(array, array + n);
    
    vector<long long> costs;
    costs.reserve(n);
    for (long long r = 1; r < n; r++){
        if(array[r] - array[r - 1] > x){
            long long dist = array[r] - array[r - 1];
            long long amount = dist / x - 1ll;
            if(dist % x != 0ll)
                amount++;
            
            costs.push_back(amount);
        }
    }
    //O(nlogn)
    sort(costs.begin(), costs.end());

    long long currGroups = costs.size() + 1ll;
    long long currK = k;
    for (long long i = 0; i < costs.size(); i++){
        if(costs[i] <= currK){
            currK -= costs[i];
            currGroups--;
        }
        else{
            break;
        }
    }

    cout << currGroups;
}