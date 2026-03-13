#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    string hotel;
    cin >> hotel;

    int minL = 0;
    int minR = INT_MAX;

    int minDist = INT_MAX;

    int l = 0;
    int r = 0;
    int currK = k + 1;
    while(r < n){
        if(currK > 0){
            //search
            if(hotel[r] == '0'){
                if(currK == k + 1)
                    l = r;
                currK--;
            }
            r++;
        }
        else{
            //update max and check dist
            if(r - l <= minR - minL){
                minR = r;
                minL = l;

                int farmL = l;
                int farmR = r;
                int farmM = (farmL + farmR) / 2;
                for (int i = minL; i < minR; i++){
                    if(hotel[i] == '0'){
                        minDist = min(minDist, max(i - minL, minR - i - 1));
                    }
                }
            }
            //find next l
            if(hotel[l] == '0'){
                currK++;
            }
            for (int i = l + 1; i < r; i++){
                if(hotel[i] == '0'){
                    l = i;
                    break;
                }
            }
        }
    }
    //post cycle check
    if(currK == 0){
        if(r - l <= minR - minL){
            minR = r;
            minL = l;
            for (int i = minL; i < minR; i++){
                if(hotel[i] == '0'){
                    minDist = min(minDist, max(i - minL, minR - i - 1));
                }
            }
        }
    }

    cout << minDist;
}