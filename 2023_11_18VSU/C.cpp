#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int s, n;
    cin >> s >> n;

    int* weights = new int[n];
    for (int i = 0; i < n; i++){
        cin >> weights[i];
    }

    sort(weights, weights + n);

    bool* data = new bool[s + 1];
    data[0] = true;
    for (int i = 1; i < s + 1; i++){
        data[i] = false;
    }
    for (int i = 0; i < n; i++){
        int currw = weights[i];
        for (int j = s; j >= 0; j--){
            if(currw <= j){
                data[j] = data[j] || data[j - currw];
            }
        }
    }
    
    for (int i = s; i >= 0; i--){
        if(data[i]){
            cout << i;
            return 0;
        }
    }
    cout << 0;
}