#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

const long long modulo = 1000000007;
unordered_map<long long, long long> factDict {{0, 1}};
long long currFactNum = 0;
long long factModulo(long long n){
    if(n <= currFactNum){
        return factDict[n];
    }

    long long currFact = factDict[currFactNum];
    for (long long i = currFactNum + 1; i <= n; i++){
        currFact = (currFact * i) % modulo;
        factDict[i] = currFact;
    }
    currFactNum = n;
    return factDict[n];
}

int numDigits2(int n){
    int counter = 0;
    while(n > 0){
        n /= 2;
        counter++;
    }

    return counter;
}

void toBin(int* array, int n){
    int index = 0;
    while(n > 0){
        int cypher = n % 2;
        array[index++] = cypher;
        n /= 2;
    }
}

long long fastPowModulo(long long num, long long pow){
    if(pow == 0){
        return 1;
    }

    if(pow % 2ll == 0){
        long long result = fastPowModulo(num, pow / 2ll);
        return (result * result) % modulo;
    }
    return (num * fastPowModulo(num, pow - 1ll)) % modulo;
}

long long inverseModulo(long long n){
    return fastPowModulo(n, modulo - 2);
}

long long accomodation(long long n, long long k){
    long long result = factModulo(n);
    result = (result * inverseModulo(factModulo(n - k))) % modulo;

    return result;
}

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        int* array = new int[n];
        int maxNum = 0;
        for (int i = 0; i < n; i++){
            cin >> array[i];
            maxNum = max(maxNum, array[i]);
        }

        int nd = numDigits2(maxNum);
        int** binArray = new int*[n];
        for (int i = 0; i < n; i++){
            binArray[i] = new int[nd];
            fill(binArray[i], binArray[i] + nd, 0);

            toBin(binArray[i], array[i]);
        }

        set<int> goodIndexes;
        bool failed = false;
        bool foundIndexes = false;
        for (int j = 0; j < nd; j++){
            //count 0 and 1
            int amount0 = 0;
            for (int i = 0; i < n; i++){
                if(binArray[i][j] == 0)
                    amount0++;
            }

            if(amount0 == 0){
                continue;
            }
            if(amount0 == 1){
                failed = true;
                break;
            }

            if(!foundIndexes){
                foundIndexes = true;
                for (int i = 0; i < n; i++){
                    if(binArray[i][j] == 0)
                        goodIndexes.insert(i);
                }
            }
            else{
                //otherwise correct good indexes
                for (int i = 0; i < n; i++){
                    if(binArray[i][j] == 1){
                        goodIndexes.erase(i);
                    }
                }
                if(goodIndexes.size() < 2){
                    failed = true;
                    break;
                }
            }
        }
        
        if(failed)
            cout << "0\n";
        else if(!foundIndexes)
            cout << factModulo(n) << "\n";
        else
            cout << (accomodation(goodIndexes.size(), 2) * factModulo(n - 2)) % modulo << "\n"; //goodIndexes.size()! * (n - goodIndexes.size())!
    }
}