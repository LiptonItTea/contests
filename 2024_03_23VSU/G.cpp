#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const long long border = 1000000000000ll;

int countOnes(long long n){
    int counter = 0;
    while (n > 0ll){
        int cypher = n % 2;
        counter += cypher == 1;
        n /= 2;
    }
    return counter;
}

unordered_map<int, long long> factDict {{0, 1}};
int currFactNum = 0;
long long fact(int n){
    if(n <= currFactNum)
        return factDict[n];
    
    long long currFact = factDict[currFactNum];
    for (int i = currFactNum + 1; i <= n; i++){
        currFact *= i;
        factDict[i] = currFact;
    }
    currFactNum = n;
    return factDict[n];
}

int main(){
    vector<long long> numDict;

    long long currNum = 1;
    int currIndex = 0;
    while(currNum <= border){
        numDict.push_back(currNum);
        currNum = fact(++currIndex);
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        long long n;
        cin >> n;

        int bestResult = INT_MAX;
        for (int mask = 0; mask < (1 << numDict.size()); mask++){
            long long currSum = 0;
            int counter = 0;
            for (int i = 0; i < numDict.size(); i++){
                if(mask & 1 << i){
                    currSum += numDict[i];
                    counter++;
                }
            }

            if(currSum > n){
                continue;
            }

            counter += countOnes(n - currSum);
            bestResult = min(bestResult, counter);
        }

        cout << bestResult << "\n";
    }
}