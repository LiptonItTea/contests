#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        int* array = new int[n];
        cin >> array[0];
        
        int l = 0;
        int maxSub = 0;
        for (int r = 1; r < n; r++){
            cin >> array[r];
            if(array[r - 1] >= array[r]){
                maxSub = max(maxSub, array[r - 1] - array[l]);
                l = r;
            }
        }
        maxSub = max(maxSub, array[n - 1] - array[l]);

        cout << maxSub << "\n";
    }
}