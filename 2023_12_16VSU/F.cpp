#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int* array = new int[n];
    int mid = 0;
    for (int i = 0; i < n; i++){
        cin >> array[i];
        mid += array[i];
    }
    
    if(mid % (2 * n - 1) == 1){
        cout << "NO";
        return 0;
    }

    mid /= 2 * n - 1;

    for (int i = 1; i < n; i++){
        if(array[i - 1] < mid || array[i] < mid){
            cout << "NO";
            return 0;
        }

        if(array[i] - mid + array[i - 1] - mid < mid){
            cout << "NO";
            return 0;
        }
        else{
            if(array[i - 1] - mid > mid){
                cout << "NO";
                return 0;
            }

            array[i] -= mid - (array[i - 1] - mid);
            array[i - 1] -= array[i - 1] - mid;
        }
    }
    if(array[n - 1] != mid){
        cout << "NO";
        return 0;
    }

    // for (int i = 0; i < n; i++){
    //     cout << array[i] << " ";
    // }
    // cout << "\n";

    cout << "YES";
}