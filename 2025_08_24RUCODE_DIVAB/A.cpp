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

    int s;
    cin >> s;

    int time;
    cin >> time;

    if (s == 0) {
        cout << "F";
        return 0;
    }

    if (s <= 4) {
        cout << "CDE";
        return 0;
    }

    if (s != 9) {
        cout << "AB";
        return 0;
    }

    if (time <= 180) {
        cout << "A-";
        return 0;
    }

    cout << "AB";
}