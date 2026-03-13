#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, d, c;
    cin >> n >> p >> d >> c;

    int* data = new int[n];
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }

    int kmax = ceil(((double) p) / ((double) d)) + 1;
    //0 - not done
    //1 - false
    //2 - true
    int* results = new int[kmax];
    for (int i = 0; i < kmax; i++){
        results[i] = 2;
    }

    int l = 0;
    int r = kmax;
    int k = (r + l) / 2;
    while (true){
        int* newData = new int[n];
        for (int i = 0; i < n; i++){
            newData[i] = data[i] - p + d * k - c * k;
        }
        for (int i = 0; i < n - 1; i++){
            if(newData[i] > 0){
                newData[i + 1] += newData[i];
                newData[i] = 0;
            }
        }
        bool good = true;
        for (int i = 0; i < n; i++){
            if(newData[i] < 0){
                good = false;
                break;
            }
        }
        results[k] = good;
        // cout << "left: " << l << " right: " << r << " K: " << k << "\n";
        // for (int i = 0 ; i < kmax; i++){
        //     cout << results[i] << " ";
        // }
        // cout << "\n";
        if(k == 0){
            cout << 0 << "\n";
            return 0;
        }
        if(k == kmax - 1 && results[k - 1] == false){
            cout << k << "\n";
            return 0;
        }
        if(results[k - 1] == false && results[k] == true){
            cout << k << "\n";
            return 0;
        }
        if(results[k] == false){
            l = k;
        }
        else{
            r = k - 1;
        }
        k = (r + l) / 2;
        delete newData;
    }
}