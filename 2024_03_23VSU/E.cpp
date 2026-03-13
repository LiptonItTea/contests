#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        int* array = new int[n];
        for (int i = 0; i < n; i++)
            cin >> array[i];
        
        long long bestResult = LLONG_MIN;
        int bestL = -1;
        int bestR = -1;

        //divide array by 0
        int l = 0;
        int r = 0;
        while(r < n){
            if(array[r] != 0){
                r++;
                if(r < n)
                    continue;
            }

            int negativeCount = 0;
            for (int i = l; i < r; i++){
                if(array[i] < 0)
                    negativeCount++;
            }

            if(negativeCount % 2 == 0){
                long long currResult = 0;
                for (int i = l; i < r; i++){
                    if(abs(array[i]) == 2)
                        currResult++;
                }

                if(currResult > bestResult){
                    bestResult = currResult;
                    bestL = l;
                    bestR = r;
                }
            }
            else{
                //find first negative and last negative
                int firstNegativeIndex = -1;
                int lastNegativeIndex = -1;
                for (int i = l; i < r; i++){
                    if(array[i] < 0){
                        if(firstNegativeIndex == -1)
                            firstNegativeIndex = i;
                        lastNegativeIndex = i;
                    }
                }

                long long currResult = 0;
                for (int i = l; i < lastNegativeIndex; i++){
                    if(abs(array[i]) == 2)
                        currResult++;
                }
                if(currResult > bestResult){
                    bestResult = currResult;
                    bestL = l;
                    bestR = lastNegativeIndex;
                }

                currResult = 0;
                for (int i = firstNegativeIndex + 1; i < r; i++){
                    if(abs(array[i]) == 2)
                        currResult++;
                }
                if(currResult > bestResult){
                    bestResult = currResult;
                    bestL = firstNegativeIndex + 1;
                    bestR = r;
                }
            }
            r++;
            l = r;
        }

        if(bestResult != LLONG_MIN)
            cout << bestL <<  " " << (n - bestR) << "\n";
        else
            cout << n << " 0\n";
    }
}