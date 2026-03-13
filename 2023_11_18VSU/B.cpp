#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* data = new int[n + 1];
    data[0] = 1;
    data[1] = 1;
    for (int i = 2; i < n + 1; i++){
        data[i] = data[i - 1] + data[i - 2];
    }
    cout << data[n];
}