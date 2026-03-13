#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    if(k == 1){
        cout << 0;
        return 0;
    }

    for (int i = k; i >= 1; i--)
        cout << i << " ";
    for (int i = k + 1; i <= n; i++){
        cout << i << " ";
    }
}