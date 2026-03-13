#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, x;
        cin >> n >> x;

        if (n == 1) {
            cout << x << "\n";
            continue;
        }

        if (n == 2) {
            cout << 0 << " " << x << "\n";
            continue;
        }

        vector<int> result;
        for (int i = 0; i <= x && result.size() < n; i++) {
            
            if ((x | i) == x) {
                result.push_back(i);
            }
            else{
                break;
            }
        }
        // check whether we can
        int pseudox = 0;
        for (int i = 0; i < result.size(); i++) {
            pseudox = (pseudox | result[i]);
        }

        if (pseudox != x){
            if (result.size() == n)
                result.pop_back();
            result.push_back(x);
        }

        while (result.size() < n) {
            result.push_back(0);
        }

        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << '\n';
    }
}