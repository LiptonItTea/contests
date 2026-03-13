#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long n, d;
    cin >> n >> d;

    long long* array = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    sort(array, array + n);
    // for (int i = 0; i < n; i++)
    //     cout << array[i] << " ";
    // cout << "\n";
    
    long long* dists = new long long[n];
    long long currSum = 0;
    for (int i = 1; i < n; i++){
        currSum += abs(array[i] - array[0]);
    }
    dists[0] = currSum;
    if(dists[0] == d){
        cout << "YES\n";
        cout << array[0];
        return 0;
    }
    for (long long i = 1; i < n; i++){
        long long delta = i - (n - i);
        currSum += delta * (array[i] - array[i - 1]);
        dists[i] = currSum;
        
        if(dists[i] == d){
            cout << "YES\n";
            cout << array[i];
            return 0;
        }
    }

    // for (int i = 0; i < n; i++)
    //     cout << dists[i] << " ";
    // cout << "\n";

    if(d > dists[0]){
        if((d - dists[0]) % n == 0){
            long long alpha = (d - dists[0]) / n;
            cout << "YES\n";
            cout << array[0] - alpha;
            return 0;
        }
    }
    if(d > dists[n - 1]){
        if((d - dists[n - 1]) % n == 0){
            long long alpha = (d - dists[n - 1]) / n;
            cout << "YES\n";
            cout << array[n - 1] + alpha;
            return 0;
        }
    }

    for (long long i = 1; i < n; i++){
        if(dists[i - 1] < d && d < dists[i] || 
            dists[i - 1] > d && d > dists[i]){
            long long delta = i - (n - i);
            if(delta == 0)
                continue;
            if((d - dists[i - 1]) % delta == 0){
                long long alpha = (d - dists[i - 1]) / delta;
                cout << "YES\n";
                cout << array[i - 1] + alpha;
                return 0;
            }
        }
    }
    cout << "NO";
}