#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        long long n;
        cin >> n;

        long long sum = 0;
        for (int i = 0; i < n; i++){
            long long currNum;
            cin >> currNum;

            sum += currNum;
        }

        long long modulo = sum % n;

        cout << modulo * (n - modulo) << "\n";
    }
}