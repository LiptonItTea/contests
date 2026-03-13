#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    for (int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;

        cout << max(n, m) + 1 << "\n";
    }
}