#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> k >> n;
    
    int amount = 0;
    int copyn = n;
    while(copyn > 0){
        amount++;
        copyn /= 10;
    }
    int sum = 0;
    while(n > 0){
        int curr = n % 10;
        if(k - amount < 0){
            amount--;
        }
        else{
            sum += curr;
        }
        n /= 10;
    }
    cout << sum;
}