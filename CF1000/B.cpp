#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

bool compareV(pair<int, long long> p1, pair<int, long long> p2) {
    return p1.second < p2.second;
}

long long solve(vector<pair<int, long long>>& part, int l, int r) {
    long long result = 0;
    for (int i = 0, c = 0; i < part.size() && i < r - l + 1 && c < r - l + 1; i++){
        result += part[i].second;
        if (part[i].first < l || r < part[i].first)
            c++;
    }
    return result;
}

int main() {
    // freopen("test.in", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        long long n, l, r;
        cin >> n >> l >> r;

        vector<pair<int, long long>> a (n, {-1, -1});
        vector<pair<int, long long>> leftPart, rightPart;
        for (int i = 0; i < n; i++){
            long long v;
            cin >> v;

            a[i].first = i + 1;
            a[i].second = v;

            if (i + 1 <= r)
                leftPart.push_back(a[i]);
            if (l <= i + 1)
                rightPart.push_back(a[i]);
        }
        sort(leftPart.begin(), leftPart.end(), compareV);
        sort(rightPart.begin(), rightPart.end(), compareV);

        int len = r - l + 1;
        
        long long minSum = solve(leftPart, l, r);
        minSum = min(minSum, solve(rightPart, l, r));

        cout << minSum << "\n";
    }
}