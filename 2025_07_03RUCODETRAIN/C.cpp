#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int main() {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    
    int n;
    cin >> n;

    vector<int> a (n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int t;
    cin >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            cout << "retest " << i + 1 << endl;
            
            int code;
            cin >> code;
            
            if (code == 0)
                break;
        }
        cout << "done" << endl;
    }
}