#include <iostream>

using namespace std;

int main(){
    long long n, p, k;
    cin >> n >> p >> k;

    if(n >= p){
        cout << p;
        return 0;
    }

    long long l = 0;
    long long r = n + 1;
    long long amountK = (l + r) / 2;
    long long drawMax = INT_MIN;
    while(true){
        long long amountDraw = min(max(0ll, p - amountK * k), n - amountK);
        long long amountLoss = n - amountDraw - amountK;
        
        if(amountK * k + amountDraw == p){
            drawMax = max(drawMax, amountDraw);
        }

        if(amountLoss > 0){
            r = amountK;
        }
        else{
            l = amountK;
        }
        long long prevK = amountK;
        amountK = (l + r) / 2;
        if(prevK == amountK)
            break;
    }
    if(drawMax == INT_MIN){
        cout << -1;
        return 0;
    }
    cout << drawMax;
}