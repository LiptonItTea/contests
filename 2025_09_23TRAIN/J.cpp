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
#include <bitset>

#define ll long long

using namespace std;

string solve(string &s, int i, int j) {
    string result (s);
    for (int k = j; k >= i; k--)
        result[s.size() - 1 - (k - i)] = (s[s.size() - 1 - (k - i)] - '0' | s[s.size() - 1 - k] - '0') + '0';
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int i = 0;
    while (i < n && s[i] == '0')
        i++;

    if (i == n) {
        cout << 0;
        return 0;
    }

    while (i < n && s[i] == '1')
        i++;
    
    if (i == n) {
        cout << s;
        return 0;
    }

    string lex_best = "0";
    for (int j = i; j >= 0; j--) {
        lex_best = max(lex_best, solve(s, j, s.size() - 1));
    }
    
    int j = 0;
    while (j < n && lex_best[j] == '0')
        j++;

    if (j == n)
        cout << '0';
    while (j < n)
        cout << lex_best[j++];
}