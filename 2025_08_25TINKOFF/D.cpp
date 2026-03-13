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

    vector<int> l (n), r (n), a (n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i] >> a[i];

    vector<int> prefa (n + 1);
    for (int i = 1; i < n + 1; i++)
        prefa[i] = prefa[i - 1] + a[i - 1];


    vector<int> right_res (n);
    int j = 1;
    int delta = 0;

    right_res[0] = a[0];
    int flow_right = delta;
    while (flow_right < r[0]) {
        delta = min(a[j], r[0] - flow_right);
        right_res[0] += delta;
        flow_right += delta;
        j++;
    }

    for (int i = 1; i < n; i++) {
        right_res[i] = prefa[j] - prefa[i] + delta;
        int flow_right = delta;
        
        while (flow_right < r[i]) {
            delta = min(a[j], r[i] - flow_right);
            right_res[i] += delta;
            flow_right += delta;
            j++;
        }
    }
}