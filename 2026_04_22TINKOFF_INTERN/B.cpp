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

    string s;
    cin >> s;
    int n = s.size();

    int acount = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a')
            acount++;
        else
            break;
    }

    for (int i = 0; i < (n - acount) / 2; i++) {
        if (s[i] != s[n - 1 - acount - i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}