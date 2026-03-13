#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    for (int _ = 0; _ < t; _++){
        long long n, x;
        cin >> n >> x;

        long long* array = new long long[n];
        for (int i = 0; i < n; i++)
            cin >> array[i];
        
        long long min1Add = array[0] - 1ll;
        for (int i = 1; i < n; i++){
            min1Add = min(min1Add, 2ll * (min(array[i - 1], array[i]) - 1ll));
        }
        min1Add = min(min1Add, array[n - 1] - 1ll);

        long long minXAdd = abs(array[0] - x);
        if(array[0] >= x)
            minXAdd = 0;
        for (int i = 1; i < n; i++){
            if(array[i - 1] <= x && x <= array[i]){
                minXAdd = 0;
                break;
            }
            if(array[i - 1] >= x){ //according to previous condition, every member is bigger than x
                minXAdd = 0;      //this means that x is connected to 1 placement
                break;
            }
            minXAdd = min(minXAdd, 2ll * (x - max(array[i - 1], array[i])));
        }
        minXAdd = min(minXAdd, abs(x - array[n - 1]));
        if(array[n - 1] >= x)
            minXAdd = 0;

        long long result = 0;
        for (int i = 1; i < n; i++)
            result += abs(array[i - 1] - array[i]);
        result += min1Add;
        result += minXAdd;

        cout << result << "\n";
    }
}