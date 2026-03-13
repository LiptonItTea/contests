#include <iostream>

using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;

    int* array = new int[n + 1];
    array[0] = 0;
    for (int i = 1; i < n + 1; i++){
        cin >> array[i];
        array[i] += array[i - 1];
    }

    long long multSum = 0;
    for (int i = 1; i < n + 1; i++){
        for (int j = 0; j < i; j++){
            int curSum = array[i] - array[j];
            for (int k = 1; k <= i; k++){
                for (int l = 0; l < k; l++){
                    if(k == i && l <= j){
                        continue;
                    }
                    int prevSum = array[k] - array[l];

                    long long mult = ((long long) curSum % m) * ((long long) prevSum % m);
                    multSum = (multSum + mult) % m;
                }
            }
        }
    }
    cout << multSum;
}