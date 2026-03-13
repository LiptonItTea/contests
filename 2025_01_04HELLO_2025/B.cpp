#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool compareSecond(pair<int, int>& first, pair<int, int>& second) {
    return first.second > second.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, k;
        cin >> n >> k;

        map<int, int> amounts;
        for (int i = 0; i < n; i++) {
            int cypher;
            cin >> cypher;

            amounts[cypher]++;
        }

        if (amounts.size() == 1) {
            cout << "1\n";
            continue;
        }

        if (k == 0) {
            cout << amounts.size() << "\n";
            continue;
        }

        vector<pair<int, int>> rev;
        for (auto it = amounts.begin(); it != amounts.end(); it++) {
            rev.push_back(*it);
        }
        sort(rev.begin(), rev.end(), compareSecond);
        
        // int totalSum = 0;
        // for (int i = 0; i < rev.size() - 1; i++) {
        //     totalSum += rev[i].second;
        // }
        // totalSum -= k;
        // totalSum = max(totalSum, 0);

        // cout << totalSum + 1 << "\n";

        for (int i = 0; i < k; i++) {
            if (rev.size() == 0)
                break;
            
            rev[rev.size() - 1].second--;
            if (rev[rev.size() - 1].second == 0)
                rev.pop_back();
        }

        if (rev.size() == 0 || rev.size() == 1)
            cout << "1\n";
        else
            cout << rev.size() << "\n";
    }
}