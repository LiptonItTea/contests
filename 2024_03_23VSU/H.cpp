#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int>* toBin(int n){
    vector<int> result;
    result.reserve(20);

    while(n > 0){
        result.push_back(n % 2);
        n /= 2;
    }
    while(result.size() < 20)
        result.push_back(0);

    vector<int>* reversed = new vector<int>;
    reversed->reserve(20);
    for (auto it = result.rbegin(); it != result.rend(); it++){
        reversed->push_back(*it);
    }

    return reversed;
}

int count(vector<int>* bina, vector<int>* binb){
    vector<int> lbina = *bina;
    vector<int> lbinb = *binb;

    int firstOne;
    for (int i = 0; i < 20; i++){
        if(lbina[i] == 1){
            firstOne = i;
            break;
        }
    }

    int submaskB = 0;
    int subMaskA = 0;
    for (int i = 0; i <= 19 - firstOne; i++){
        if(lbinb[19 - i] == 1)
            submaskB += pow(2, i);
        
        if(lbina[19 - i] == 1)
            subMaskA += pow(2, i);
    }
    if(subMaskA < submaskB)
        return submaskB - subMaskA;
    return subMaskA - submaskB;
}

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int a, b;
        cin >> a >> b;

        // vector<int>* bina = toBin(a);
        // vector<int>* binb = toBin(b);

        // for (auto it = bina->begin(); it != bina->end(); it++)
        //     cout << *it;
        // cout << "\n";
        // for (auto it = binb->begin(); it != binb->end(); it++)
        //     cout << *it;
        // cout << "\n";

        // int result = count(bina, binb) + 1;

        // cout << min(result, b - a) << "\n";
        int bestResult = INT_MAX;

        int currA = a;
        int currB = b;
        int currResult = 0;
        while((currA | currB) != currB){
            currA++;
            currResult++;
        }
        bestResult = min(bestResult, currResult + (currA != currB));

        currA = a;
        currResult = 0;
        while((currA | currB) != currB){
            currB++;
            currResult++;
        }
        bestResult = min(bestResult, currResult + (currA != currB));

        cout << bestResult << "\n";
    }
}

/*
стратегии
1. без |: добить a до b
2. с |:
а. добить а до подмаски b, объединить
b. объединить, добить b до a
с. добить b до 

3. довести одно число до подмаски другого, сравнить затраты
	если уже достигли нужного числа, то пох

 */