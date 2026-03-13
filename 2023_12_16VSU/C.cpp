#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int* b = new int[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    int maxLeftBound = INT_MIN;
    int minRightBound = INT_MAX;
    for (int i = 0; i < n; i++){
        int left = min(a[i], b[i]);
        int right = max(a[i], b[i]);
        
        maxLeftBound = max(maxLeftBound, left);
        minRightBound = min(minRightBound, right);
    }

    cout << max(0, minRightBound - maxLeftBound + 1);
}