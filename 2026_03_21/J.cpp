#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>

using namespace std;

struct Bound {
    int l, r, u, d;
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<string> f (n);
    for (int i = 0; i < n; i++)
        cin >> f[i];

    string orders;
    cin >> orders;

    vector<vector<Bound>> b (n, vector<Bound> (m));
    for (int i = 0; i < n; i++) {
        int l = 0;
        for (int j = 0; j < m; j++) {
            if (f[i][j] == '#')
                l = j + 1;
            b[i][j].l = l;
        }
    }
    for (int i = 0; i < n; i++) {
        int r = m - 1;
        for (int j = m - 1; j >= 0; j--) {
            if (f[i][j] == '#')
                r = j - 1;
            b[i][j].r = r;
        }
    }
    for (int j = 0; j < m; j++) {
        int u = 0;
        for (int i = 0; i < n; i++) {
            if (f[i][j] == '#')
                u = i + 1;
            b[i][j].u = u;
        }
    }
    for (int j = 0; j < m; j++) {
        int d = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (f[i][j] == '#')
                d = i - 1;
            b[i][j].d = d;
        }
    }

    int x = 0, y = n - 1;
    for (int k = 0; k < orders.size(); k++) {
        if (orders[k] == 'U')
            y = b[y][x].u;
        if (orders[k] == 'R')
            x = b[y][x].r;
        if (orders[k] == 'D')
            y = b[y][x].d;
        if (orders[k] == 'L')
            x = b[y][x].l;
    }
    cout << x + 1 << " " << n - 1 - y + 1;
}