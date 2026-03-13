#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int* array = new int[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    sort(array, array + n);
    int lowerBound = array[b - 1];
    int upperBound = array[b];
    cout << upperBound - lowerBound;
}