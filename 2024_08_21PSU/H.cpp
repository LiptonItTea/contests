#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    int bestResult = INT_MIN;
    string bestLeft;
    string bestRight;
    for (int l = 1; l <= n - 1; l++){
        string left = s.substr(0, l);
        for (int r = 1; r <= (n - l); r++){
            string right = s.substr(n - r, r);

            int i = 0;
            int leftCounter = 0;
            bool good = true;
            while(i < n){
                //check a
                if(i + 1 + left.length() <= n){
                    bool a = true;
                    for (int j = 0; j < left.length(); j++){
                        if(s[i + j] != left[j]){
                            a = false;
                            break;
                        }
                    }
                    if(a){
                        i += left.length();
                        leftCounter++;
                        continue;
                    }
                }
                //check b
                if(i + right.length() <= n){
                    bool b = true;
                    for (int j = 0; j < right.length(); j++){
                        if(s[i + j] != right[j]){
                            b = false;
                            break;
                        }
                    }
                    if(b){
                        i += right.length();
                        leftCounter--;
                        if(leftCounter < 0){
                            good = false;
                            break;
                        }
                        continue;
                    }
                }

                //nor a nor b
                good = false;
                break;
            }

            if(good && leftCounter == 0){
                int currK = n / (left.length() + right.length()) * 2;
                if(bestResult < currK){
                    bestResult = currK;
                    bestLeft = left;
                    bestRight = right;
                }
            }
        }
    }

    cout << bestLeft << " " << bestRight;
}