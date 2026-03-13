#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    long long* array = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    sort(array, array + n);

    long long l = 0;
    long long r = array[n - 1] + 2;
    long long d = (l + r) / 2;
    while(true){
        long long points = 0;
        for (int i = 0; i < n; i++){
            if(array[i] >= d)
                points += 3;
            else
                points += 2;
        }

        if(points == k)
            break;
        
        if(points > k)
            l = d;
        else
            r = d;
        
        d = (l + r) / 2;
    }

    for (int i = 0; i < n; i++){
        if(array[i] >= d){
            if(i == 0){
                cout << 0;
                break;
            }
            cout << array[i - 1] + 1;
            break;
        }
    }
    if(array[n - 1] < d){
        cout << array[n - 1] + 1;
    }
}