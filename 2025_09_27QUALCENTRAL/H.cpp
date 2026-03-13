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

// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    vector<int> r (2000000 + 10, 0);
    for (int i = 2; i < r.size(); i++) {
        if (r[i] != 0)
            continue;

        for (int j = i; j < r.size(); j += i)
            if (r[j] == 0)
                r[j] = i;
    }

    int n;
    cin >> n;

    vector<int> arr (r.size(), -1);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        if (arr[k] != -1) {
            cout << arr[k] + 1 << " " << i + 1;
            return 0;
        }
        // if (arr.find(k) != arr.end()) {
        //     cout << arr[k] + 1 << " " << i + 1;
        //     return 0;
        // }

        arr[k] = i;
    }

    for (auto i = 0; i < arr.size(); i++) {
        if (arr[i] == -1) {
            continue;
        }
        int a = i;;

        while (a > 1) {
            if (arr[a / r[a]] != -1) {
                cout << (arr[i] + 1) << " " << (arr[a / r[a]] + 1);
                return 0;
            }

            if (arr[r[a]] != -1 && r[a] != a) {
                cout << (arr[i] + 1) << " " << (arr[r[a]] + 1);
                return 0;
            }

            a /= r[a];
        }
    }

    // for (auto it = arr.begin(); it != arr.end(); it++) {
    //     int a = it->first;

    //     while (a > 1) {
    //         if (arr.find(a / r[a]) != arr.end()) {
    //             cout << (arr.find(it->first)->second + 1) << " " << (arr.find(a / r[a])->second + 1);
    //             return 0;
    //         }

    //         if (arr.find(r[a]) != arr.end() && r[a] != a) {
    //             cout << (arr.find(it->first)->second + 1) << " " << (arr.find(r[a])->second + 1);
    //             return 0;
    //         }

    //         a /= r[a];
    //     }
    // }

    cout << "0 0";
}