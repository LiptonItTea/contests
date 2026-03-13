#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>

#define ll long long

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b;
    set<int> found;
    for (int i = n - 1; i >= 0; i--) {
        if (found.find(a[i]) == found.end()) {
            b.push_back(a[i]);
            found.insert(a[i]);
        }
    }

    cout << b.size() << "\n";
    for (auto it = b.rbegin(); it != b.rend(); it++)
        cout << *it << " ";
}