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
    cin >> n;

    multiset<int> s1, s2, s3, s4, s5;
    vector<string> all (n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        all[i] = s;

        int full_sum = 0;
        for (int j = 0; j < s.size(); j++)
            full_sum += s[j] - '0';

        int pref = 0;
        for (int j = 0; j < s.size(); j++) {
            pref += s[j] - '0';
            
            if (2 * j + 1 < s.size())
                continue;
            
            if (2 * j + 1 - s.size() == 0)
                s1.insert(pref - (full_sum - pref));
            if (2 * j + 1 - s.size() == 1)
                s2.insert(pref - (full_sum - pref));
            if (2 * j + 1 - s.size() == 2)
                s3.insert(pref - (full_sum - pref));
            if (2 * j + 1 - s.size() == 3)
                s4.insert(pref - (full_sum - pref));
            if (2 * j + 1 - s.size() == 4)
                s5.insert(pref - (full_sum - pref));
        }
        pref = 0;
        for (int j = s.size() - 1; j >= 1; j--) {
            pref += s[j] - '0';
            
            if (2 * j + 1 > s.size())
                continue;
            
            if (s.size() - (2 * j + 1) == 0)
                s1.insert(pref - (full_sum - pref));
            if (s.size() - (2 * j + 1) == 1)
                s2.insert(pref - (full_sum - pref));
            if (s.size() - (2 * j + 1) == 2)
                s3.insert(pref - (full_sum - pref));
            if (s.size() - (2 * j + 1) == 3)
                s4.insert(pref - (full_sum - pref));
            if (s.size() - (2 * j + 1) == 4)
                s5.insert(pref - (full_sum - pref));
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        string s = all[i];
        int pref = 0;
        for (int j = 0; j < s.size(); j++)
            pref += s[j] - '0';

        if (s.size() == 5 && s5.find(pref) != s5.end())
            for (auto it = s5.lower_bound(pref); it != s5.end(); it++){
                if (*it == pref)
                    result++;
                else
                    break;
            }
        if (s.size() == 4 && s4.find(pref) != s4.end())
            for (auto it = s4.lower_bound(pref); it != s4.end(); it++){
                if (*it == pref)
                    result++;
                else
                    break;
            }
        if (s.size() == 3 && s3.find(pref) != s3.end())
            for (auto it = s3.lower_bound(pref); it != s3.end(); it++){
                if (*it == pref)
                    result++;
                else
                    break;
            }
        if (s.size() == 2 && s2.find(pref) != s2.end())
            for (auto it = s2.lower_bound(pref); it != s2.end(); it++){
                if (*it == pref)
                    result++;
                else
                    break;
            }
        if (s.size() == 1 && s1.find(pref) != s1.end())
            for (auto it = s1.lower_bound(pref); it != s1.end(); it++){
                if (*it == pref)
                    result++;
                else
                    break;
            }
    }

    cout << result;
}