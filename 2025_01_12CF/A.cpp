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

    for (int  _ = 0; _ < t; _++) {
        int n, a, b;
        cin >> n >> a >> b;

        cout << (((a % 2) == (b % 2)) ? "YES\n" : "NO\n");
    }
}