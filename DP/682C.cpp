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

int answer = 0;
void dfs(int curr, int prev, vector<vector<int>>& links, vector<vector<ll>>& weights, vector<ll>& a, ll currdist, ll shortest, bool remove) {
    shortest = min(shortest, currdist);

    if (currdist - shortest > a[curr])
        remove = true;
    if (remove)
        answer++;

    for (int i = 0; i < links[curr].size(); i++) {
        int next = links[curr][i];
        ll w = weights[curr][i];

        if (next == prev)
            continue;

        dfs(next, curr, links, weights, a, currdist + w, shortest, remove);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<vector<int>> links (n);
    vector<vector<ll>> weights (n);
    vector<ll> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;

        links[i + 1].push_back(p - 1);
        links[p - 1].push_back(i + 1);
        weights[i + 1].push_back(c);
        weights[p - 1].push_back(c);
    }

    dfs(0, -1, links, weights, a, 0, 0, false);

    cout << answer;
}