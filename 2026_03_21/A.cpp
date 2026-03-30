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

    int n, m;
    cin >> n >> m;

    vector<string> f (n);
    for (int i = 0; i < n; i++)
        cin >> f[i];

    vector<string> nf (n, string (m, '.'));

    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m ; j++) {
            bool bad = false;

            for (int di = -1; di < 2; di++) {
                for (int dj = -1; dj < 2; dj++) {
                    if (i+di>=0 && i+di<n && j+dj>=0 && j+dj<m && f[i + di][j + dj] == '.') {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                    break;
            }

            if (bad)
                continue;

            for (int di = -1; di < 2; di++) {
                for (int dj = -1; dj < 2; dj++) {
                    if (i+di>=0 && i+di<n && j+dj>=0 && j+dj<m)
                        f[i + di][j + dj] = 'p';
                }
            }
            nf[i][j] = '#';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == '#') {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    cout << "Possible\n";
    for (int i = 0; i < n; i++) {
        cout << nf[i] << "\n";
    }
}