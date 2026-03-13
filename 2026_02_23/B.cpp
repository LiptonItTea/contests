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

struct Group {
    int val, amnt;
};

bool compare_groups(Group &g1, Group &g2) {
    return g1.amnt > g2.amnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<Group> compressed;
    int preva; cin >> preva;
    int amnt = 1;
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;

        if (a == preva) {
            amnt++;
            continue;
        }
        compressed.push_back({preva, amnt});
        amnt = 1;
        preva = a;
    }
    compressed.push_back({preva, amnt});

    sort(compressed.begin(), compressed.end(), compare_groups);

    map<int, int> aux;
    int best = compressed.begin()->amnt;
    for (int i = 0; i < compressed.size(); i++) {
        if (aux.find(compressed[i].val) == aux.end()) {
            aux[compressed[i].val] = compressed[i].amnt;
            continue;
        }

        int amnt_other = aux.find(compressed[i].val)->second;

        best = max(best, amnt_other + compressed[i].amnt);
    }

    cout << best;
}