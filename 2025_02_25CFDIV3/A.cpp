#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n, k, p;
        cin >> n >> k >> p;

        if (n * p < abs(k)) {
            cout << "-1\n";
            continue;
        }
        if (k < 0)
            k *= -1;

        cout << k / p + (k % p != 0) << "\n";
    }
}