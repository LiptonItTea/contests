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

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cout << fixed << setprecision(9);

    int n, k;
    cin >> n >> k;

    int m;
    cin >> m;

    vector<int> balls (m);
    for (int i = 0; i < m; i++)
        cin >> balls[i];

    sort(balls.begin(), balls.end());

    if (n >= m) {
        cout << "enter\n";
        return 0;
    }

    if (balls[m - n] > k) {
        cout << "no chance\n";
        return 0;
    }
    else if (balls[m - n] == k && balls[m - n + 1] == k) {
        cout << "entrance exams\n";
        return 0;
    }
    else {
        cout << "enter\n";
    }
}