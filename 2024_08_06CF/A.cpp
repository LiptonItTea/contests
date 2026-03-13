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

        int a = n % 10;
        int b = n / 10;

        cout << a + b << "\n";
    }
}