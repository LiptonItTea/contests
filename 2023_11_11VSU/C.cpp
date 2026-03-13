#include <iostream>

using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    if (n % 2 == 1){
        cout << 0;
        return 0;
    }
    int check = (n / 2) % 2 == 0 ? 1 : 0;
    cout << n / 4 - check;
}