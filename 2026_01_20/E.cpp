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

    int n, q;
    cin >> n >> q;

    vector<vector<int>> links(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        links[l - 1].push_back(r);
        links[r].push_back(l - 1);
    }

    vector<int> dist(n + 1, -1);
    queue<int> qu;

    qu.push(0);
    dist[0] = 0;

    while (!qu.empty()) {
        int curr = qu.front();
        qu.pop();

        if (curr == n) {
            break;
        }

        for (int next : links[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                qu.push(next);
            }
        }
    }

    if (dist[n] != -1) {
        cout << "Yes" << "\n" << dist[n];
    } else {
        cout << "No";
    }

    return 0;
}