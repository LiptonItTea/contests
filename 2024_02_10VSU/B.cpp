#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n % 2 != 0){
        cout << 0;
        return 0;
    }
    n /= 2;
    cout << (int) pow(2, n) << endl;
}