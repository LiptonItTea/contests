#include <iostream>

using namespace std;

long long combination5(long long n){
    long long numerator = 1;
    for (int i = 0; i < 5; i++){
        numerator *= n - i;
    }
    numerator /= 120ll;
    return numerator;
}

long long accomodation5(long long n){
    long long numerator = 1;
    for (int i = 0; i < 5; i++){
        numerator *= n - i;
    }
    return numerator;
}

int main(){
    long long n;
    cin >> n;

    cout << combination5(n) * accomodation5(n);
}