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

    int n;
    string our, adv;
    cin >> n >> our >> adv;

    vector<vector<int>> pref (n + 1, vector<int> (3, 0));
    for (int i = 0; i < n; i++) {
        pref[i + 1][0] = pref[i][0] + (adv[i] == 'a');
        pref[i + 1][1] = pref[i][1] + (adv[i] == 'b');
        pref[i + 1][2] = pref[i][2] + (adv[i] == 'c');
    }
    vector<int> counts (3);
    for (int i = 0; i < n; i++)
        counts[our[i] - 'a']++;

    for (int i = 0; i < n; i++) {
        for (char c = 'a'; c < 'd'; c++) {
            if (c == adv[i])
                continue;
            
            if (counts[c - 'a'] == 0)
                continue;

            counts[c - 'a']--;

            bool good = true;
            for (char j = 'a'; j < 'd'; j++) {
                if (counts[j - 'a'] > (n - i - 1) - (pref[n][j - 'a'] - pref[i + 1][j - 'a'])){
                    good = false;
                    break;
                }
            }

            if (good) {
                cout << c;
                break;
            }

            counts[c - 'a']++;
        }
    }
}