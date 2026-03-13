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
        ll n;
        cin >> n;

        string s;
        cin >> s;
        
        ll under_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '_') 
                under_count++;
        }

        ll left = (n - under_count) / 2ll;
        cout << left * under_count * (n - left - under_count) << "\n";
    }
}