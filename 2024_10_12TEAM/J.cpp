#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double eps = 0.00001;

int digits(long long i){
    int counter = 0;
    while(i > 0){
        i /= 10;
        counter++;
    }

    return counter;
}

long long inv(long long i){
    long long result = 0;
    long long tenPow = pow(10, digits(i) - 1);

    while(i > 0){
        result += (i % 10) * tenPow;
        tenPow /= 10;
        i /= 10;
    }

    return result;
}

int main() {
    long long a, b;
    cin >> a >> b;

    int n = 316227;
    vector<long long> dict (n + 1);

    for (long long i = 0; i * i <= n; i++){
        long long j = inv(i * i);
        long long sqrtj = sqrt(j);
        if(digits(i * i) == digits(j) && abs(((double) sqrtj) - sqrt(j)) < eps){
            dict[i * i] = 1;
            if(j <= n)
                dict[j] = 1;
        }
    }

    int i = 0;
    while(i * i < a)
        i++;
    
    int counter = 0;
    while(i * i <= b){
        counter += dict[i * i];
        // if(dict[i * i] == 1)
        //     cout << i * i << '\n';
        i++;
    }

    cout << counter;
}