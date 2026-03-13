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

bool comp(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

bool sus(int i, int j) {
    return i > j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<pair<int, int>> a (n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), comp);

    int neg_amnt = 0;
    int zer_amnt = 0;

    int max_neg = -1;
    int max_neg_v = 0;
    int last_zero = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].first < 0){
            neg_amnt++;
            if (a[i].first < max_neg_v) {
                max_neg_v = a[i].first;
                max_neg = i;
            }
        }
        else if (a[i].first == 0){
            zer_amnt++;
            last_zero = i;
        }
        else
            continue;
    }

    
    if (neg_amnt % 2 == 0) {
        for (int i = 0; i < n - 1; i++)
            if (a[i].first != 0 && a[i + 1].first != 0)
                cout << "1 " << i + 1 << " " << i + 2 << "\n";
            else if (a[i].first == 0 && a[i + 1].first == 0)
            else if (a[i].first != 0 && i != n - 2)
                cout << "1 " << i + 1 << " " << i + 3 << "\n";

        cout << "2 " << last_zero + 1;
    }
    else {
        for (int i = 0; i < n - 1; i++)
            cout << "1 " << i + 1 << " " << i + 2 << "\n";
    }
    return 0;
    

    // zer_amnt = 0
    // if (neg_amnt % 2 == 0){
    //     for (int i = 0; i < n - 1; i++)
    //         cout << "1 " << i + 1 << " " << i + 2 << "\n";
    // }
    // else {
    //     for (int i = 0; i < n - 1; i++)
    //         if (a[i].first != max_neg && a[i + 1].first != max_neg)
    //             cout << "1 " << i + 1 << " " << i + 2 << "\n";
    //         else if (a[i].first != max_neg && i != n - 2)
    //             cout << "1 " << i + 1 << " " << i + 3 << "\n";
    //     cout << "2 " << max_neg + 1;
    // }
}