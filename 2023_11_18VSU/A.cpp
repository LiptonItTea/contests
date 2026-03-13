#include <iostream>

using namespace std;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int* data = new int[n + 1];
    data[0] = 0;
    for (int i = 1; i < n + 1; i++){
        int ai = i - a;
        int bi = i - b;
        int ci = i - c;
        int result = 0;
        if(ai == 0 || (ai > 0 && data[ai] > 0))
            result = max(result, data[ai] + 1);
        if(bi == 0 ||(bi > 0 && data[bi] > 0))
            result = max(result, data[bi] + 1);
        if(ci == 0 || (ci > 0 && data[ci] > 0))
            result = max(result, data[ci] + 1);
        
        data[i] = result;
    }
    cout << data[n];
}