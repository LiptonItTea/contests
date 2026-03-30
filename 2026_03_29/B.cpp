#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cout << fixed << setprecision(9);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int total = a + b - c;

    int clearA = total - b;
    int clearB = total - a;

    if (clearA > d || clearB > d) {
        cout << "No\n";
        return 0;
    }

    int deltaA = min(d - clearA, c);
    c -= deltaA;

    int deltaB = min(d - clearB, c);
    c -= deltaB;

    if (c > 0) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
}