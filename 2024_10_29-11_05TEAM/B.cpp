#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compareSecond(pair<int, int>& first, pair<int, int>& second) {
    return first.second<second.second;
}

int main() {
    freopen("test.in", "r", stdin);
    int k, n;
    cin >> k >> n;

            //cipher amount
    vector<pair<int, int>> colorsAmount (n, {0, 0});
    for (int i = 0; i < n; i++) {
        colorsAmount[i].first = i + 1;
    }

    vector<int> original (k, 0);
    for (int i = 0; i < k; i++) {
        int color;
        cin >> color;

        if (color == -1)
            color = 1;

        colorsAmount[color - 1].second++;
        original[i] = color;
    }
    sort(colorsAmount.begin(), colorsAmount.end(), compareSecond);

    int l = 0;
    while (colorsAmount[l].second == 0)
        l++;
    
    int r = n - 1;
    cout << "Yes" << "\n";
    map<int, vector<int>> result;
    while (l < r) {
        int leftColor = colorsAmount[l].first;
        int rightColor = colorsAmount[r].first;

        int leftAmount = colorsAmount[l].second;
        int rightAmount = colorsAmount[r].second;

        for (int i = 0; i < min(leftAmount, rightAmount); i++) {
            result[leftColor].push_back(rightColor);
            result[rightColor].push_back(leftColor);
        }
        colorsAmount[l].second -= min(leftAmount, rightAmount);
        colorsAmount[r].second -= min(leftAmount, rightAmount);

        if (leftAmount <= rightAmount)
            l++;
        if (rightAmount <= leftAmount)
            r--;
    }
    if (l == r) {
        int color = colorsAmount[l].first;
        int amount = colorsAmount[l].second;

        for (int i = 0; i < amount; i++) {
            result[color].push_back(color);
        }
    }

    for (int i = 0; i < k; i++){
        vector<int>& vars = result[original[i]];
        cout << original[i] << " " << vars[vars.size() - 1] << "\n";
        vars.pop_back();
    }

    return 0;
}