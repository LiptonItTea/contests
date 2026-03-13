#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int d = min(a, min(b, c));
    int f = max(a, max(b, c));
    int e = a + b + c - d - f;

    //d - e - f
    int amount = d;
    f -= d;
    amount += e;
    f -= e;
    if(abs(f % 2) == 1){
        cout << -1;
        return 0;
    }
    amount += f / 2;
    cout << amount;
}