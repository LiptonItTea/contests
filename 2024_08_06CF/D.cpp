#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        string s, t;
        cin >> s >> t;

        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j])
                j++;
            if (s[i] == '?') {
                s[i] = t[j];
                j++;
            }
            i++;
        }

        if (j == t.size()) {
            for (int k = i; k < s.size(); k++)
                if (s[k] == '?')
                    s[k] = 'a';
            
            cout << "YES\n" << s << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
}