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

    vector<int> p (n);
    for (int i = 0; i < n; i++) 
        cin >> p[i];

    sort(p.begin(), p.end());

    int cursum = 0;
    int amnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (cursum + p[i] <= p[n - 1]){
            cursum += p[i];
            amnt++;
        }
        else
            break;
    }

    cout << amnt + 1;
}