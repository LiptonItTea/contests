#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a (n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1){
        cout << a[0];
        return 0;
    }
    
    int index = n / 2 - 1;

    //basic median check
    if (n % 2 == 0){
        if (a[index] % 2 != a[index + 1] % 2){
            cout << -1;
            return 0;
        }
    }
    
    for (int i = index; i >= 0; i--){
        cout << a[i] << " " << a[n - 1 - i] << " ";
    }
    if (n % 2 == 1)
        cout << a[index + 1];
}