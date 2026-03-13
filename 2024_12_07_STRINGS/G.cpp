#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> z (s.size(), 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        
        while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }

    for (int i = 0; i < s.size(); i++)
        cout << z[i] << " ";
    cout << "\n";

    vector<int> pi (s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        
        if (s[j] == s[i])
            j++;
        pi[i] = j;
    }

    for (int i = 0; i < s.size(); i++)
        cout << pi[i] << " ";
}