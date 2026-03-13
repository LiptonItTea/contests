#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

const long long modu = 998244353;

unordered_map<long long, long long> factDict = {{0, 1}};
long long currDictNum = 0;
long long factModu(long long n){
    if(n <= currDictNum)
        return factDict[n];
    
    long long currFact = factDict[currDictNum];
    for (long long i = currDictNum + 1; i <= n; i++){
        currFact = (currFact * i) % modu;
        factDict[i] = currFact;
    }
    currDictNum = n;
    return factDict[n];
}

bool compareFirst(long long* a1, long long* a2){
    return a1[0] < a2[0];
}
bool compareSecond(long long* a1, long long* a2){
    return a1[1] < a2[1];
}
bool compareFirstSecond(long long* a1, long long* a2){
    if(a1[0] < a2[0])
        return true;
    else if(a1[0] > a2[0])
        return false;
    
    return a1[1] < a2[1];
}

int main(){
    long long n;
    cin >> n;

    long long** pairsSortedFirstIndexes = new long long*[n];
    long long** pairsSortedSecondIndexes = new long long*[n];
    long long** pairsSortedFirstSecondIndexes = new long long*[n];
    for (int i = 0; i < n; i++){
        pairsSortedFirstIndexes[i] = new long long[2];
        cin >> pairsSortedFirstIndexes[i][0] >> pairsSortedFirstIndexes[i][1];

        pairsSortedSecondIndexes[i] = new long long[2];
        pairsSortedSecondIndexes[i][0] = pairsSortedFirstIndexes[i][0];
        pairsSortedSecondIndexes[i][1] = pairsSortedFirstIndexes[i][1];

        pairsSortedFirstSecondIndexes[i] = new long long[2];
        pairsSortedFirstSecondIndexes[i][0] = pairsSortedFirstIndexes[i][0];
        pairsSortedFirstSecondIndexes[i][1] = pairsSortedFirstIndexes[i][1];
    }

    sort(pairsSortedFirstIndexes, pairsSortedFirstIndexes + n, compareFirst);
    sort(pairsSortedSecondIndexes, pairsSortedSecondIndexes + n, compareSecond);
    sort(pairsSortedFirstSecondIndexes, pairsSortedFirstSecondIndexes + n, compareFirstSecond);

    // cout << "First indexes\n";
    // for (int i = 0; i < n; i++)
    //     cout << pairsSortedFirstIndexes[i][0] << "\n";
    // cout << "\nSecond indexes\n";
    // for (int i = 0; i < n; i++)
    //     cout << pairsSortedSecondIndexes[i][1] << "\n";
    // cout << "\nFirst and Second indexes\n";
    // for (int i = 0; i < n; i++)
    //     cout << pairsSortedFirstSecondIndexes[i][0] << " " << pairsSortedFirstSecondIndexes[i][1] << "\n";
    // cout << "\n";

    long long result = factModu(n);
    
    //phase 1 - count first indexes' accomodations in first indexes' sorted array
    unordered_map<long long, long long> counter;
    for (int i = 0; i < n; i++){
        counter[pairsSortedFirstIndexes[i][0]]++;
    }
    long long currPairs = 1;
    for (unordered_map<long long, long long>::iterator it = counter.begin(); it != counter.end(); it++){
        currPairs = (currPairs * factModu(it->second)) % modu;
    }
    result = (result - currPairs) % modu;
    if(result < 0)
        result += modu;

    //phase 2 - count first indexes' accomodations in first indexes' sorted array
    counter.clear();
    for (int i = 0; i < n; i++){
        counter[pairsSortedSecondIndexes[i][1]]++;
    }
    currPairs = 1;
    for (unordered_map<long long, long long>::iterator it = counter.begin(); it != counter.end(); it++){
        currPairs = (currPairs * factModu(it->second)) % modu;
    }
    result = (result - currPairs) % modu;
    if(result < 0)
        result += modu;

    //phase 3 - count equal pairs accomodations
    bool hasBothSorted = true;
    for (int i = 1; i < n; i++){
        if(pairsSortedFirstSecondIndexes[i][0] > pairsSortedFirstSecondIndexes[i][1]){
            hasBothSorted = false;
            break;
        }
    }
    if(hasBothSorted){
        map<pair<long long, long long>, long long> equalsCounter;
        for (int i = 0; i < n; i++){
            pair<long long, long long> p {pairsSortedFirstSecondIndexes[i][0], pairsSortedFirstSecondIndexes[i][1]};
            equalsCounter[p]++;
        }

        currPairs = 1;
        for (map<pair<long long, long long>, long long>::iterator it = equalsCounter.begin(); it != equalsCounter.end(); it++){
            currPairs = (currPairs * factModu(it->second)) % modu;
        }
        result = (result + currPairs) % modu;
    }
    
    cout << result;
}