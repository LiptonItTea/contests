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

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        string s;
        cin >> s;

        int longest = INT_MIN;
        int current = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                current++;
            }
            else { 
                longest = max(longest, current);
                current = 0;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                current++;
            }
            else { 
                longest = max(longest, current);
                current = 0;
                break;
            }
        }
        longest = max(longest, current);
        longest = min(longest, (int) s.size());

        if (longest == s.size()) {
            long long n = s.size();
            cout << n * n << "\n";
            continue;
        }

        long long h = (longest + 1) / 2;
        long long w = longest - h + 1;
        cout << h * w << "\n";
    }
}