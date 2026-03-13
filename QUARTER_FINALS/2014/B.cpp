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

bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int k, n;
    cin >> k >> n;

    vector<int> c (k);
    vector<pair<int, int>> amnts (n, {-1, 0});
    for (int i = 0; i < k; i++){
        cin >> c[i];
        if (c[i] != -1) {
            amnts[c[i] - 1].first = c[i];
            amnts[c[i] - 1].second++;
        }
    }

    vector<pair<int, int>> res (k, {-1, -1});
    for (int i = 0; i < k; i++) {
        res[i].first = c[i];
    }

    int currk = k;
    int currn = n;
    while (currk > 0) {
        sort(amnts.begin(), amnts.end(), comp);

        int l = 0;
        while (l < n && amnts[l].second <= 0)
            l++;
        
        if (l == n) {
            for (int j = 0; j < k; j++)
                if (res[j].first == -1 && res[j].second == -1)
                    res[j].first = res[j].second = 1;
            break;
        }

        int smaller = amnts[l].first;
        int bigger = amnts[n - 1].first;

        if (l == n - 1) {
            for (int j = 0; j < k; j++) {
                if (res[j].first == bigger && res[j].second == -1)
                    res[j].second = 1;
                else if (res[j].first == -1 && res[j].second == -1) {
                    res[j].first = bigger;
                    res[j].second = 1;
                }
            }
            break;
        }

        int num_of_big = currk / currn - amnts[l].second;
        for (int j = 0; j < k && num_of_big > 0; j++) {
            if (res[j].first == bigger && res[j].second == -1) {
                res[j].second = smaller;
                num_of_big--;
            }
        }
        if (num_of_big > 0) {
            for (int j = 0; j < k && num_of_big > 0; j++) {
                if (res[j].first == -1 && res[j].second == -1) {
                    res[j].first = smaller;
                    res[j].second = bigger;
                    num_of_big--;
                }
            }
        }
        for (int j = 0; j < k; j++) {
            if (res[j].first == smaller && res[j].second == -1) {
                res[j].second = bigger;
            }
        }
        amnts[n - 1].second -= currk / currn - amnts[l].second;
        amnts[l].second = 0;

        currk -= currk / currn;
        currn -= 1;
    }

    cout << "Yes\n";
    for (int i = 0; i < k; i++) {
        cout << res[i].first << " " << res[i].second << "\n";
    }
}