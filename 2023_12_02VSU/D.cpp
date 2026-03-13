#include <iostream>
#include <map>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long newN = n;
    for (long long i = 2; i * i <= newN; i++){
        if(newN % i == 0){
            long long rest = newN / i;
            if(rest % 2 == 0){
                cout << i * rest / 2;
                return 0;
            }
            else{
                cout << 1 + (i * (rest - 1) / 2);
                return 0;
            }
        }
    }
    
    cout << 1;
}