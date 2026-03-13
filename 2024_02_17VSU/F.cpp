#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>

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

vector<int> perm(int n, long long k){
    set<int> numSet;
    for (int i = 1; i <= n; i++)
        numSet.insert(i);
    
    vector<int> result;
    result.reserve(n);

    k %= fact(n);
    for (int i = 1; i <= n; i++){
        int alreadyWas = k / fact(n - i);
        k %= fact(n - i);

        auto it = numSet.begin();
        for (int j = 0; j < alreadyWas; j++){
            it++;
        }
        result.push_back(*it);
        numSet.erase(it);
    }

    return result;
}

bool checkGood(int n){
    while(n > 0){
        int cipher = n % 10;
        if(cipher != 4 && cipher != 7){
            return false;
        }
        n /= 10;
    }
    return true;
}

void recurseLuckIndexes(long long n, set<int>& indexes, string& currIndex){
    currIndex += '4';
    long long currNum = stoll(currIndex);
    if(currNum <= n){
        indexes.insert(currNum);
        recurseLuckIndexes(n, indexes, currIndex);
        currIndex.pop_back();

        currIndex += '7';
        currNum = stoll(currIndex);
        if(currNum <= n){
            indexes.insert(currNum);
            recurseLuckIndexes(n, indexes, currIndex);
            currIndex.pop_back();
        }
        else{
            currIndex.pop_back();
            return;
        }
    }
    else{
        currIndex.pop_back();
        return;
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    set<int> indexes;
    string temp;
    recurseLuckIndexes(n, indexes, temp);

    if(n <= 14){
        if(fact(n) < ((long long) k)){
            cout << -1;
            return 0;
        }
    }

    int maxIndex = 0;
    for (int i = 0; i <= n; i++){
        if(fact(i) < k){
            maxIndex = i;
        }
        else{
            break;
        }
    }

    int counter = 0;
    auto it = indexes.begin();
    while(it != indexes.end() && *it < n - maxIndex){
        counter++;
        it++;
    }
    // for (int i = 1; i < n - maxIndex; i++){
    //     bool good = checkGood(i);
    //     if(good)
    //         counter++;
    // }

    vector<int> rest = perm(maxIndex + 1, k - 1);
    // for (int i = 0; i < rest.size(); i++){
    //     int index = i + (n - maxIndex);
    //     int num = rest[i] + (n - maxIndex) - 1;

    //     if(checkGood(index) && checkGood(num)){
    //         counter++;
    //     }
    // }
    while(it != indexes.end() && *it <= n){
        int index = (*it) - (n - maxIndex);
        int num = rest[index] + (n - maxIndex - 1);
        if(checkGood(num)){
            counter++;
        }
        it++;
    }
    cout << counter;
}