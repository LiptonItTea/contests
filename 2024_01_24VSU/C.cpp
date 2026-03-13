#include <iostream>
#include <bitset>

using namespace std;

int main(){
    unsigned long long n;
    int k;
    cin >> n;
    cin >> k;

    // first part - calculate array of amount of 1 in binary view.
    int* array = new int[n];
    if(n > 0)
        array[0] = 0;
    if(n > 1)
        array[1] = 1;
    
    int boundLPower = 1;
    int boundRPower = 2;
    int boundLLNum = 1;
    int boundLNum = pow(2, boundLPower);
    int boundRNum = pow(2, boundRPower);
    int middle = (boundLNum + boundRNum) / 2;
    for (unsigned long long num = 2; num < n; num++){
        // recalculate bounds
        if (num == boundRNum){
            boundLPower++;
            boundRPower++;
            boundLLNum = boundLNum;
            boundLNum = boundRNum;
            boundRNum = pow(2, boundRPower);
            middle = (boundLNum + boundRNum) / 2;
        }
        if(num < middle){
            array[num] = array[num - boundLNum + boundLLNum];
        }
        else{
            array[num] = array[num - middle + boundLNum] + 1;
        }
    }
    // for (int i = 0; i < n; i++){
    //     cout << array[i] << endl;
    // }

    unsigned long long amount = 0;
    // second part - calculate amount of k-good segments
    int firstGood = 0;
    for (int i = 0; i < n; i++){
        if(array[i] > k){
            // it means there is fully good segment on [firstGood, i - 1]
            int len = i - firstGood;
            for (unsigned long long j = 1; j <= len; j++){
                amount += j;
            }
            firstGood = i + 1;
        }
        if(i == n - 1){
            unsigned long long len = i + 1 - firstGood;
            for (unsigned long long j = 1; j <= len; j++){
                amount += j;
            }
        }
    }

    cout << amount;
}