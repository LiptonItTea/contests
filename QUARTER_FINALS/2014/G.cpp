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

    int n, k;
    cin >> n >> k;

    vector<int> a (n);
    int mv = INT_MAX;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mv = min(mv, a[i]);
    }

    int currsum = 0;
    int i = 0;
    while (i < k)
        currsum += a[i++];

    int result = 0;
    while (i < n) {
        int j = i - 1;
        while (currsum >= 0) {
            int delta = min(a[j] - mv, currsum + 1);
            a[j] -= delta;
            currsum -= delta;
            result += delta;
            j--;
        }
        currsum -= a[i - k];
        currsum += a[i];
        i++;
    }
    int j = i - 1;
    while (currsum >= 0) {
        int delta = min(a[j] - mv, currsum + 1);
        a[j] -= delta;
        currsum -= delta;
        result += delta;
        j--;
    }

    cout << result << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}