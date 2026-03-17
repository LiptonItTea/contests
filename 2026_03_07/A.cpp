#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int order = a[0] < a[1] ? 1 : -1;
    bool switched = false;
    for (int i = 1; i < n - 1; i++) {
        int curr_order = a[i] < a[i + 1] ? 1 : -1;

        if (order != curr_order) {
            if (!switched){
                switched = true;
                order = curr_order;
            }
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }

    if (!switched)
        cout << "NO\n";
    else
        cout << "YES\n";
}