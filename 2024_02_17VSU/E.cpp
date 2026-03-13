#include <iostream>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

unordered_map<int, long long> factDict {{0, 1}};
int currFactNum = 0;
long long fact(int n){
    if(n <= currFactNum){
        return factDict[n];
    }

    long long currFact = factDict[currFactNum];
    for (int i = currFactNum + 1; i <= n; i++){
        currFact *= i;
        factDict[i] = currFact;
    }
    currFactNum = n;
    return factDict[n];
}

void perm(int n, long long k){
    set<int> numSet;
    for (int i = 1; i <= n; i++)
        numSet.insert(i);

    k %= fact(n);
    for (int i = 1; i <= n; i++){
        long long alreadyWas = k / fact(n - i);
        k %= fact(n - i);
        
        auto it = numSet.begin();
        for (int j = 0; j < alreadyWas; j++){
            it++;
        }
        cout << *it << " ";
        numSet.erase(it);
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        long long p;
        cin >> p;

        perm(n, p - 1);
    }
}