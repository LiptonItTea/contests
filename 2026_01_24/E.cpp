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

    int n;
    cin >> n;

    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        counts[a[i]]++;
    }

    vector<bool> fine (100000 + 1, false);
    fine[min(a[n - 2], min(a[n - 1], a[0]))] = true;
    fine[max(a[n - 2], max(a[n - 1], a[0]))] = true;
    fine[min(a[n - 1], min(a[0], a[1]))] = true;
    fine[max(a[n - 1], max(a[0], a[1]))] = true;

    fine[min(a[n - 2], min(a[n - 1], a[0]))] = true;
    fine[max(a[n - 2], max(a[n - 1], a[0]))] = true;
    fine[min(a[n - 1], min(a[0], a[1]))] = true;
    fine[max(a[n - 1], max(a[0], a[1]))] = true;    
    for (int i = 0; i < n; i++) {
        if (i >= 2){
            fine[min(a[i - 2], min(a[i - 1], a[i]))] = true;
            fine[max(a[i - 2], max(a[i - 1], a[i]))] = true;
        }
        if (i >= 1 && i <= n - 2) {
            fine[min(a[i - 1], min(a[i], a[i + 1]))] = true;
            fine[max(a[i - 1], max(a[i], a[i + 1]))] = true;
        }
        if (i <= n - 3) {
            fine[min(a[i], min(a[i + 1], a[i + 2]))] = true;
            fine[max(a[i], max(a[i + 1], a[i + 2]))] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        int result = n - counts[a[i]];
        if (!fine[a[i]])
            result++;
        
        cout << result << ' ';
    }
}