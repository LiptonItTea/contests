#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* kangoroo = new int[n];
    for (int i = 0; i < n; i++){
        cin >> kangoroo[i];
    }

    sort(kangoroo, kangoroo + n);

    // for (int i = 0; i < n; i++){
    //     cout << kangoroo[i] << " ";
    // }
    // cout << "\n";

    // int l = n - 1;
    // int r = n - 1;
    // int overall = n;
    // while(l >= 0){
    //     if(kangoroo[r] == -1){
    //         r--;
    //         continue;
    //     }
    //     while(l >= 0 && kangoroo[l] * 2 > kangoroo[r]){
    //         l--;
    //     }
    //     if(l >= 0){
    //         kangoroo[l] = -1;
    //         overall--;
    //         l--;
    //         r--;
    //     }
    // }
    int l = 0;
    int r = n / 2;
    while(l < n / 2 && r < n){
        if(kangoroo[l] * 2 <= kangoroo[r]){
            l++;
            r++;
        }
        else{
            r++;
        }
    }
    cout << n - l;
}