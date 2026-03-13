#include <iostream>
#include <list>
#include <math.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, k;
        cin >> n >> k;
        
        int* digits = new int[31];
        for (int i = 0; i < 31; i++){
            digits[i] = 0;
        }
        list<int> digitsList;
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;

            digitsList.clear();
            while(num > 0){
                int rest = num % 2;
                digitsList.push_back(rest);
                num /= 2;
            }
            //todo get size by comparing with 2' pows and remove this garbage
            int j = 31 - digitsList.size();
            for (auto it = digitsList.rbegin(); it != digitsList.rend(); it++){
                digits[j++] += (*it);
            }
        }

        int currK = k;
        for (int i = 0; i < 31; i++){
            if(digits[i] + currK >= n){
                currK -= n - digits[i];
                digits[i] = n;
            }
        }

        int result = 0;
        for (int i = 0; i < 31; i++){
            if(digits[i] == n){
                result += pow(2, 30 - i);
            }
        }
        cout << result << "\n";
    }
}