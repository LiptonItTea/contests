#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* data = new int[n];
    for (int i = 0; i < n; i++)
        cin >> data[i];
    
    int curSum = 0, maxSum = data[0];
    int curLeft = 0, curRight = 0;
    int maxLeft = 0, maxRight = 0;

    for (int i = 0; i < n; i++){
        if(curSum >= 0){
            curSum += data[i];
            curRight = i;
        }
        else{
            if(curSum + data[i] > data[i]){
                curSum += data[i];
                curRight = i;
            }
            else{
                curSum = data[i];
                curLeft = i;
                curRight = i;
            }
        }
        if(curSum > maxSum){
            maxSum = curSum;
            maxLeft = curLeft;
            maxRight = curRight;
        }
    }
    if(curSum > maxSum){
        maxSum = curSum;
        maxLeft = curLeft;
        maxRight = curRight;
    }
    cout << maxLeft + 1 << " " << maxRight + 1;
}