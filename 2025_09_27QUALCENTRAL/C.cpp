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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    map<char, int> alphabet;

    for (char c = '0'; c <= '9'; c++)
        alphabet[c] = c - '0';
    for (char c = 'A'; c <= 'Z'; c++)
        alphabet[c] = c - 'A' + 10;
    
    alphabet[' '] = 36;
    alphabet['$'] = 37;
    alphabet['%'] = 38;
    alphabet['*'] = 39;
    alphabet['+'] = 40;
    alphabet['-'] = 41;
    alphabet['.'] = 42;
    alphabet['/'] = 43;
    alphabet[':'] = 44;
    
    string s;
    getline(cin, s);

    string result;
    for (int i = 0; i < s.size(); i += 2) {
        if (i == s.size() - 1) {
            bitset<6> num (alphabet[s[i]]);
            
            result += num.to_string();
            break;
        }

        bitset<11> num (alphabet[s[i]] * 45 + alphabet[s[i + 1]]);
        result += num.to_string();
    }

    cout << result;
}