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

    double x0, y0, x1, y1;
    int n;
    cin >> x0 >> y0 >> x1 >> y1 >> n;

    double a0 = atan2(y0, x0);
    double a1 = atan2(y1, x1);
    double angle = a1 - a0;

    double result = a0 + angle * n;
    cout << cos(result) << " " << sin(result);
}