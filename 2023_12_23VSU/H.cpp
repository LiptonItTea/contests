#include <iostream>
#include <string>
#include <math.h>
#include <stdint.h>

using namespace std;
 
const int64_t modulo = 1000000007;
 
int64_t fastPowModulo(int64_t num, int64_t pow){
    if(pow == 0)
        return 1;
    
    if(pow % 2 == 0){
        int64_t result = fastPowModulo(num, pow / 2);
        return (result * result) % modulo;
    }
    return (num * fastPowModulo(num, pow - 1)) % modulo;
}
 
int64_t inverseModulo(int64_t num){
    return fastPowModulo(num, modulo - 2);
}
 
int main(){
    int64_t inverse2 = 500000004;
    // cout << "reading numbers" << endl;
    string num;
    cin >> num;
    // cout << "got numbers" << endl;

    int64_t currAdditionSum = 0;
    for (int64_t j = 0; j + 2 <= num.length(); j++){
        int64_t addition = (j + 1) % modulo;
        addition = (addition * fastPowModulo(10, j)) % modulo;
        // addition = (addition * cypher) % modulo;
        currAdditionSum = (currAdditionSum + addition) % modulo;
    }
 
    int64_t result = 0;
    for (int64_t i = 0; i < num.length(); i++){
        //idea: count what sum will we get from one cypher
        int64_t cypher = num[i] - 48;
        int64_t currSum = 0;
        //left += num[i] * i * (i - 1) / 2 * 10^(m - i) assuming 1<=i<=m
        currSum = (cypher * (i + 1)) % modulo;
        currSum = (currSum * i) % modulo;
        currSum = (currSum * inverse2) % modulo;
        currSum = (currSum * fastPowModulo(10, num.length() - i - 1));
        //right += sum by 0<=j<=m-i-1: 10^j*(j + 1) assuming 1<=i<=m
        currSum = (currSum + ((currAdditionSum * cypher) % modulo)) % modulo;
        if(i + 2 <= num.length()){
            int64_t delta = (fastPowModulo(10, num.length() - i - 2) * (((int64_t) num.length() - i - 1) % modulo)) % modulo;
            currAdditionSum = (currAdditionSum - delta) % modulo;
            if(currAdditionSum < 0)
                currAdditionSum += modulo;
        }
        result = (result + currSum) % modulo;
    }
 
    cout << result;
}