#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    // ios_base::sync_with_stdio(false);

    cout << setprecision(9) << fixed;

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
        cout << "1 " << i + 2 << "\n";
}