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

struct Warning {
    int r1, c1;
    char c;
    int r2, c2;
};

bool compw (const Warning &w1, const Warning &w2) {
    if (w1.r1 != w2.r1)
        return w1.r1 < w2.r1;
    return w1.c1 < w2.c1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<map<char, pair<int, int>>> tree;
    tree.push_back({});
    vector<Warning> wars;

    string temp;
    getline(cin, temp); // stupid hack
    for (int i = 0; i < n; i++) {
        string curr;
        getline(cin, curr);

        for (int j = 0; j < curr.size(); j++) {
            if (curr[j] == '{') {
                // expand tree
                tree.push_back({});
            }
            else if (curr[j] == '}') {
                tree.pop_back();
            }
            else if (curr[j] == ' ') {
                // continue
            }
            else {
                // var decl
                tree[tree.size() - 1][curr[j]] = {i, j};

                for (int k = tree.size() - 2; k >= 0; k--) {
                    // check previous levels for shadowing
                    if (tree[k].find(curr[j]) != tree[k].end()) {
                        auto it = tree[k].find(curr[j]);
                        wars.push_back({i, j, curr[j], it->second.first, it->second.second});
                        break;
                    }
                }
            }
        }
    }

    sort(wars.begin(), wars.end(), compw);
    
    for (int i = 0; i < wars.size(); i++) {
        cout << wars[i].r1 + 1 << ":" << wars[i].c1 + 1 << ": warning: shadowed declaration of " << wars[i].c << ", the shadowed position is " << wars[i].r2 + 1 << ":" << wars[i].c2 + 1 << "\n";
    }
}