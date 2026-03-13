#include <iostream>
#include <unordered_map>

using namespace std;

const long long modu = 1000000007;
unordered_map<int, int> factDict = {{0, 1}};
int dictCurr = 0;

long long factModu(long long n){
    if(n <= dictCurr){
        return factDict[n];
    }

    //n > dictCurr
    long long currFact = factDict[dictCurr];
    for (long long i = dictCurr + 1; i <= n; i++){
        currFact = (currFact * i) % modu;
        factDict[i] = currFact;
    }
    dictCurr = n;
    return factDict[n];
}

long long fastPowModu(long long n, long long pow){
    if(pow == 0){
        return 1;
    }

    if(pow % 2 == 0){
        long long num = fastPowModu(n, pow / 2);
        return (num * num) % modu;
    }
    return (n * fastPowModu(n, pow - 1)) % modu;
}

long long inverseModu(long long n){
    return fastPowModu(n, modu - 2);
}

long long combinationModu(long long n, long long k){
    long long result = factModu(n);
    result = (result * inverseModu(factModu(k))) % modu;
    result = (result * inverseModu(factModu(n - k))) % modu;
    return result;
}

int main(){
    long long n;
    cin >> n;

    long long result = (2 * combinationModu(2 * n - 1, n - 1)) % modu;
    result = (result - n) % modu;
    cout << result;
}