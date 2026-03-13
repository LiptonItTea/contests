#include <iostream>

using namespace std;

int euclid(int n1, int n2){
    if(n1 % n2 == 0){
        return n2;
    }
    return euclid(n2, n1 % n2);
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    double ratio1 = ((double) a) / b;
    double ratio2 = ((double) c) / d;
    int numerator, denominator;
    if(ratio1 > ratio2){
        numerator = a * d - b * c;
        denominator = a * d;
    }
    else{
        numerator = b * c - a * d;
        denominator = b * c;
    }
    int gcd = euclid(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    cout << numerator << "/" << denominator;
}