#include <iostream>

using namespace std;

const long long inf = 1000000000000000000ll;

int main(){
    long long x, y, k;
    cin >> x >> y >> k;

    long long l = 1;
    long long r = inf + 1;

    long long m = -1;
    while(true){
        long long prevM = m;
        m = (l + r) / 2;
        if(prevM == m){
            cout << -1;
            return 0;
        }

        long long rest = m;
        for (int i = 0; i < x; i++){
            rest -= rest / y;
        }

        if(rest == k)
            break;
        
        if(rest < k){
            l = m;
        }
        else{
            r = m;
        }
    }

    cout << m;
}