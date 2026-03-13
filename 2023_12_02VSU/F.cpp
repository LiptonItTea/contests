#include <iostream>
#include <set>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long newN = n;
    long long divisor = -1;
    bool bad = false;
    while(newN > 1){
        bool found = false;
        for (long long i = 2; i * i <= newN; i++){
            if(newN % i == 0){
                if(divisor != -1 && divisor != i){
                    bad = true;
                    break;
                }
                divisor = i;
                newN /= i;
                found = true;
                break;
            }
        }
        if(!found){
            if(newN != 1 && newN != n && newN != divisor){
                bad = true;
            }
            break;
        }
        if(bad)
            break;
    }
    if(newN == n){
        cout << n;
        return 0;
    }
    if(bad){
        cout << 1;
        return 0;
    }
    cout << divisor;
}