#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> factDict = {{0, 1}};
long long currFactNum = 0;
long long fact(long long n){
    if(n <= currFactNum){
        return factDict[n];
    }

    long long currFact = factDict[currFactNum];
    for (long long i = currFactNum + 1; i <= n; i++){
        currFact *= i;
        factDict[i] = currFact;
    }
    currFactNum = n;
    return currFact;
}

long long combinations(long long n, long long k){
    if(k < n - k){
        k = n - k;
    }
    long long result = 1;
    for (long long i = n; i > k; i--){
        result *= i;
    }
    return result /= fact(n - k);
}

long long fastPow(long long num, int pow){
    if(pow == 0)
        return 1;
    
    if(pow % 2 == 0){
        long long result = fastPow(num, pow / 2);
        return result * result;
    }
    return num * fastPow(num, pow - 1);
}

long long getVariants(string& num){
    int k = 0;
    long long result = 0;
    for (int i = 0; i < num.length(); i++){
        int x = num.length() - i;
        long long d = num[i] - 48;
        if(d == 0){
            continue;
        }

        //remove cipher after prefix (smaller)
        for (int j = 0; j <= min(3 - k, x - 1); j++){
            long long c = combinations(x - 1, j);
            long long p = fastPow(9, j);

            result += c * p;
        }

        //change cipher after prefix to smaller
        long long temp = 0;
        for (int j = 0; j <= min(3 - 1 - k, x - 1); j++){
            long long c = combinations(x - 1, j);
            long long p = fastPow(9, j);

            temp += c * p;
        }
        temp *= (d - 1);
        result += temp;
        k++;
    }

    //check whether number is good or not
    k = 0;
    for (int i = 0; i < num.length(); i++){
        if(num[i] - 48 > 0){
            k++;
        }
        if(k > 3){
            return result;
        }
    }
    return result + 1;
}

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        long long lll;
        cin >> lll;
        lll--;
        string l = to_string(lll);

        string r;
        cin >> r;

        long long result = getVariants(r);
        result -= getVariants(l);

        cout << result << "\n";
    }
}