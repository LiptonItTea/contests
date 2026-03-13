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
        string n;
        cin >> n;

        list<int> digs;
        for (int i = 0; i < n.size(); i++) {
            digs.push_back(n[i] - '0');
        }
        int original = stoi(n);

        set<int> result;
        for (int i = 0; i < n.size(); i++) {
            int shifted = 0;            
            int k = 1;
            for (auto it = digs.rbegin(); it != digs.rend(); it++) {
                shifted += (*it) * k;
                k *= 10;
            }

            int delta = shifted - original;
            if (delta > 0 && delta % n.size() == i) {
                result.insert(delta);
            }
            digs.push_front(digs.back());
            digs.pop_back();
        }

        cout << result.size() << "\n";
        for (int i : result)
            cout << i << " ";
        cout << "\n";
    }
}