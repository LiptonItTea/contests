#include <iostream>
#include <math.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    int* array = new int[n];
    int maxNum = 0;
    for (int i = 0; i < n; i++){
        cin >> array[i];
        maxNum = max(maxNum, array[i]);
    }

    for (int i = 0; i < n; i++){
        int result = array[i] * 100;
        cout << result / maxNum << " ";
    }
}