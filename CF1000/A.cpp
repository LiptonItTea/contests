#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int l, r;
        cin >> l >> r;

        int result = r - l;
        if (l == 1)
            result = max(1, r - l);
        
        cout << result << "\n";
    }
}