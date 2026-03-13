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

    vector<int> aux (24 * 60, 0);
    for (int i = 0; i < n; i++) {
        int sh, sm, eh, em;
        cin >> sh >> sm >> eh >> em;

        aux[sh * 60 + sm] += 1;
        aux[eh * 60 + em] += -1;
        if (sh * 60 + sm > eh * 60 + em) {
            aux[0] += 1;
            aux[aux.size() - 1] = 0;
        }
    }

    vector<int> pref (aux.size() + 1);
    pref[0] = 0;
    int best = INT_MIN;
    for (int i = 0; i < aux.size(); i++) {
        pref[i + 1] = pref[i] + aux[i];
        best = max(best, pref[i + 1]);
    }

    cout << best;
}