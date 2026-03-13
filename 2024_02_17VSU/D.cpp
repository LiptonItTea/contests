#include <iostream>

using namespace std;

int main(){
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    int* c = new int[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    
    int variants = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        int counter = 0; //must be >2
        int sum = 0;
        int easiest = INT_MAX;
        int hardest = INT_MIN;
        for (int i = 0; i < n; i++){
            if(mask & (1 << i)){
                counter++;
                sum += c[i];
                easiest = min(easiest, c[i]);
                hardest = max(hardest, c[i]);
            }
        }
        if(counter >= 2 && l <= sum && sum <= r && x <= hardest - easiest){
            variants++;
        }
    }

    cout << variants;
}