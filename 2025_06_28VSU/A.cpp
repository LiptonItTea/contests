#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cout << setprecision(9) << fixed;

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        string s;
        cin >> s;

        sort(s.begin(), s.end());

        int cf = 0;
        int cn = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'F')
                cf++;
            if (s[i] == 'N')
                cn++;
        }

        string ns = "";
        for (int i = 0; i < s.size(); i++)
            if (s[i] != 'F' && s[i] != 'N')
                ns += s[i];
        for (int i = 0; i < cf; i++)
            ns += 'F';
        for (int i = 0; i < cn; i++)
            ns += 'N';

        cout << ns << "\n";
    }
}