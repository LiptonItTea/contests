#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        if(a == k){
            k = b;
        }
        else if(b == k){
            k = a;
        }
    }

    cout << k;
}