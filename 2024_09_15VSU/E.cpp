#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    long long* corz = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> corz[i];
    sort(corz, corz + n);

    long long sumPrev = 0;
    long long maxCorz = 0;
    for (int i = 0; i < n - 1; i++)
        sumPrev += corz[i];
    maxCorz = corz[n - 1];

    if(sumPrev >= maxCorz){
        cout << sumPrev + maxCorz;
    }
    else{
        cout << sumPrev * 2 + 1;
    }
}