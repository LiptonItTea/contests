#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }

    if(a == 0)
        return b;
    if(b == 0)
        return a;
    
    return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;

    int* array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    int* prefGcd = new int[n];
    prefGcd[0] = array[0];
    for (int i = 1; i < n; i++){
        prefGcd[i] = gcd(prefGcd[i - 1], array[i]);
    }

    int* suffGcd = new int[n];
    suffGcd[n - 1] = array[n - 1];
    for (int i = n - 2; i >= 0; i--){
        suffGcd[i] = gcd(suffGcd[i + 1], array[i]);
    }

    // for (int i = 0; i < n; i++)
    //     cout << prefGcd[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < n; i++)
    //     cout << suffGcd[i] << " ";
    // cout << "\n";

    int maxGcd = prefGcd[n - 2];
    int maxIndex = n - 1;
    if(maxGcd < suffGcd[1]){
        maxGcd = suffGcd[1];
        maxIndex = 0;
    }
    for (int i = 1; i < n - 1; i++){
        int currDiv = gcd(prefGcd[i - 1], suffGcd[i + 1]);
        if(maxGcd < currDiv){
            maxGcd = currDiv;
            maxIndex = i;
        }
    }

    cout << maxIndex + 1 << " " << maxGcd;
}