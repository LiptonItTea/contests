#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int k;
        cin >> k;
        
        cout << ((k % 2 == 1) ? "YES\n" : "NO\n");
    }
}