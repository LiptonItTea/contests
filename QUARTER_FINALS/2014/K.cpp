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

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<vector<int>> cs (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cs[i][j];

        set<pair<int, int>> links;
        vector<set<int>> found (n);
        bool fine = false;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n; i++) {          
                int a = cs[i][0]; // start
                int b = cs[i][j]; // end
                found[i].insert(b);
                if (links.find({min(a, b), max(a, b)}) != links.end())
                    continue;
                
                bool bad = false;
                for (int k = 1; k < n; k++) { // iterate over j row
                    if (cs[b - 1][k] == a)
                        break;
                    if (found[i].find(cs[b - 1][k]) != found[i].end()) {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                    continue;
                
                links.insert({min(a, b), max(a, b)});

                if (links.size() == n - 1)
                    fine = true;
                if (fine)
                    break;
            }
            if (fine)
                break;
        }

        for (auto it = links.begin(); it != links.end(); it++)
            cout << it->first << " " << it->second << "\n";
    }    
}