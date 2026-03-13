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

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m, x;
        cin >> n >> m >> x;

        vector<vector<bool>> links (m + 1, vector<bool> (n, false));
        links[0][x - 1] = true;
        for (int i = 0; i < m; i++) {
            int r; char c;
            cin >> r >> c;

            for (int j = 0; j < n; j++) {
                if (!links[i][j])
                    continue;

                if (c == '0'){
                    int index = (j + r) % n;
                    links[i + 1][index] = true;
                }
                else if (c == '1'){
                    int index = (j - r);
                    if (index < 0)
                        index += n;

                    links[i + 1][index] = true;
                }
                else {
                    int index = (j + r) % n;
                    links[i + 1][index] = true;

                    index = (j - r);
                    if (index < 0)
                        index += n;

                    links[i + 1][index] = true;
                }
            }
        }

        int count = 0;
        vector<int> indices;
        for (int j = 0; j < n; j++)
            if (links[m][j]){
                count++;
                indices.push_back(j);
            }

        cout << count << "\n";
        for (int i : indices)
            cout << i + 1 << " ";
        cout << "\n";
    }
}