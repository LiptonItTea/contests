#include <iostream>
#include <unordered_map>

using namespace std;

const long long modu = 1000000007;
unordered_map<long long, long long> dict = {{0, 1}};
int dictLastNum = 0;

long long factModu(long long n){
    if(n <= dictLastNum){
        return dict[n];
    }
    
    long long result = dict[dictLastNum];
    for (long long i = dictLastNum + 1; i <= n; i++){
        result = (result * i) % modu;
        dict[i] = result;
    }
    dictLastNum = n;
    return dict[dictLastNum];
}

long long fastPowModu(long long n, long long pow){
    if(pow == 0){
        return 1;
    }

    if(pow % 2 == 0){
        long long num = fastPowModu(n, pow / 2);
        return (num * num) % modu;
    }
    else{
        return (n * fastPowModu(n, pow - 1)) % modu;
    }
}

long long inverseModu(long long n){
    //n^(-1) = n^(m-2) mod m
    return fastPowModu(n, modu - 2);
}

long long combination(long long n, long long k){
    long long result = factModu(n);
    result = (result * inverseModu(factModu(k))) % modu;
    result = (result * inverseModu(factModu(n - k))) % modu;

    return result;
}

int main(){
    int m;
    cin >> m;
    for (int _ = 0; _ < m; _++){
        long long n, k;
        cin >> n >> k;

        cout << combination(n, k) << "\n";
    }
}