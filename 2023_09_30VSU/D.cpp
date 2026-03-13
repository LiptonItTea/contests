#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    long long x;
    cin >> n >> x;

    long long* array = new long long[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    //prefSum | amount
    map<int, int> prefSums;
    prefSums[0] = 1;

    int curPrefSum = 0;
    int counter = 0;
    for (int i = 0; i < n; i++){
        curPrefSum += array[i];
        if(prefSums.find(curPrefSum - x) != prefSums.end()){
            counter += prefSums[curPrefSum - x];
        }
        prefSums[curPrefSum]++;
    }
    cout << counter;
}