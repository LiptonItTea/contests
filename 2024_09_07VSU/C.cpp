#include <iostream>

using namespace std;

int main () {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        long long u, v;
        cin >> u >> v;

        cout << u * u << " " << - v * v << "\n";
    }
}