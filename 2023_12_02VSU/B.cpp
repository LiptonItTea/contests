#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    //shift - 2
    int* colors = new int[n];
    for (int i = 0; i < n; i++){
        colors[i] = 0;
    }
    int maxColor = 1;
    for (int i = 0; i < n - 1; i++){
        int divisor = i + 2;

        for (int j = divisor * 2; j - 2 < n; j += divisor){
            if(colors[j - 2] == 0){
                colors[j - 2] = 2;
                maxColor = 2;
            }
        }
    }
    cout << maxColor << "\n";
    for (int i = 0; i < n; i++){
        cout << (colors[i] == 0 ? 1 : colors[i]) << " ";
    }
}