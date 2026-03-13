#include <iostream>
#include <math.h>

using namespace std;

long long logariphm(long long n){
    long long counter = 0;
    while(n > 1){
        n /= 2ll;
        counter++;
    }

    return counter;
}

int main(){
    long long n;
    cin >> n;
    
    if(n == 1ll){
        cout << "1 1";
        return 0;
    }

    long long nearest2 = 1ll << logariphm(n);
    if((n - nearest2) % 2ll != 0ll)
        n -= 1ll;
    long long l = nearest2 - 1ll - (n - nearest2);
    cout << l << " " << n;
}