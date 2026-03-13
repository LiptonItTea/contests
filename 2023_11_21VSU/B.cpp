#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    k--;
    int steps = n / 4;
    int curr = (k - steps) % 4;
    if(curr < 0)
        curr += 4;
    
    int amount = steps;
    if(n % 4 != 0){
        amount += (curr + 1 <= n % 4) ? 1 : 0;
    }
    cout << amount;
}