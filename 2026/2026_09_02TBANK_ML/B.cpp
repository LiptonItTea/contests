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

    map<string, int> counts;
    int best_c = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        counts[s]++;
        best_c = max(best_c, counts[s]);
    }

    set<string> best;
    for (auto it = counts.begin(); it != counts.end(); it++)
        if (it->second == best_c)
            best.insert(it->first);

    for (auto it = best.begin(); it != best.end(); it++)
        cout << *it << "\n";
}