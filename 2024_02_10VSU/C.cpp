#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const long long modu = 1000000007;

unordered_map<long long, long long> factDict = {{0, 1}};
long long currFactNum = 0;
long long factModu(long long n){
    if (n <= currFactNum){
        return factDict[n];
    }

    long long currFact = factDict[currFactNum];
    for (int i = currFactNum + 1; i <= n; i++){
        currFact = (currFact * i) % modu;
        factDict[i] = currFact;
    }
    currFactNum = n;
    return factDict[n];
}

long long fastPowModu(long long num, long long pow){
    if(pow == 0){
        return num;
    }

    if(pow % 2 == 0){
        long long result = fastPowModu(num, pow / 2);
        return (result * result) % modu;
    }
    return (num * fastPowModu(num, pow - 1)) % modu;
}

long long inverseModu(long long num){
    return fastPowModu(num, modu - 2);
}

long long combination(long long n, long long k){
    if(k < n - k){
        k = (n - k);
    }

    long long result = 1;
    for (long long i = k + 1; i <= n; i++){
        result = (result * i) % modu;
    }
    result = (result * inverseModu(factModu(n - k))) % modu;
    return result;
}

long long countForLen(long long len){
    long long mult = 1;
    for (long long i = 1; i <= len / 2; i++){
        mult = (mult + combination(len - i, i)) % modu;
    }
    return mult;
}

unordered_map<long long, long long> fibbDict {{1, 0}, {2, 1}};
long long currFibbNum = 2;
long long fibb(long long n){
    if(n <= currFibbNum){
        return fibbDict[n];
    }

    long long currFibb = fibbDict[currFibbNum];
    for (int i = currFibbNum + 1; i <= n; i++){
        currFibb = (currFibb + fibbDict[i - 2]) % modu;
        fibbDict[i] = currFibb;
    }
    currFibbNum = n;
    return fibbDict[n];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    long long result = 1;
    char prevCh = s[0];
    if(prevCh == 'w' || prevCh == 'm'){
        cout << 0;
        return 0;
    }
    int currLen = (prevCh == 'u' || prevCh == 'n') ? 1 : 0;
    for (int i = 1; i < s.length(); i++){
        char currCh = s[i];
        if(currCh == 'w' || currCh == 'm'){
            cout << 0;
            return 0;
        }
        if(prevCh == currCh && (currCh == 'u' || currCh == 'n')){
            currLen++;
        }
        else{
            result = (result * fibb(currLen + 2ll)) % modu;
            if(currCh == 'u' || currCh == 'n'){
                currLen = 1;
            }
            else{
                currLen = 0;
            }
        }
        prevCh = currCh;
    }
    result = (result * fibb(currLen + 2ll)) % modu;

    cout << result;
}