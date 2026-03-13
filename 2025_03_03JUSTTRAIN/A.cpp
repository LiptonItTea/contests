#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Entry {
    int a, s;
};

bool compares(Entry& e1, Entry e2) {
    return e1.s < e2.s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n >> p;

    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;

        if (s >= p) {
            cout << a * p << "\n";
        }
        else {
            int packsize = p / s;
            if (p % s != 0)
                packsize++;
            
            int amount = a / packsize;
            if (a % packsize != 0)
                amount++;

            cout << p * amount << "\n";
        }
    }
}