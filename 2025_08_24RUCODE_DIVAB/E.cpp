#include <iostream>
#include <math.h>
#include <map>
#include <unordered_map>
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

    int n;
    cin >> n;

    unordered_map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        counts[v]++;
    }

    int left = -1, right = -1;
    for (auto it = counts.begin(); it != counts.end(); it++) {
        if (it->second % 2 == 1){
            if (left == -1) {
                left = it->first;
                continue;
            }
            right = it->first;
            break;
        }
    }
    
    cout << min(left, right) << " " << max(left, right);
}