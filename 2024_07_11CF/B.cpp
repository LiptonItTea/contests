#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, k;
        cin >> n >> k;

        int* a = new int[k];
        for (int i = 0; i < k; i++)
            cin >> a[i];
        
        sort(a, a + k);
        int sum = 0;
        for (int i = 0; i < k - 1; i++){
            sum += a[i] - 1;
        }
        cout << sum + (sum + k - 1) << '\n';
    }
}