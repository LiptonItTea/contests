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

    vector<vector<bool>> visited (8, vector<bool> (8, 0));
    string data;
    getline(cin, data);

    int si = data[0] - 'a', sj = data[1] - '1';
    int ei = data[3] - 'a', ej = data[4] - '1';

    vector<int> dx {-1, 1, 2, 2, 1, -1, -2, -2};
    vector<int> dy {-2, -2, -1, 1, 2, 2, 1, -1};

    queue<pair<int, int>> q;
    q.push({si, sj});

    int ci, cj;
    int layercounter = 0;
    while (!q.empty()) {
        int currlayer = q.size();
        for (int layer = 0; layer < currlayer; layer++) {
            ci = q.front().first, cj = q.front().second;
            q.pop();

            if (ci == ei && cj == ej){
                cout << layercounter;
                return 0;
            }

            for (int i = 0; i < 8; i++){
                if (ci + i < 8 && cj + i < 8 && !visited[ci + i][cj + i]) {
                    q.push({ci + i, cj + i});
                    visited[ci + i][cj + i] = true;
                }
                if (ci + i < 8 && cj - i >= 0 && !visited[ci + i][cj - i]) {
                    q.push({ci + i, cj - i});
                    visited[ci + i][cj - i] = true;
                }
                if (ci - i >= 0 && cj + i < 8 && !visited[ci - i][cj + i]) {
                    q.push({ci - i, cj + i});
                    visited[ci - i][cj + i] = true;
                }
                if (ci - i >= 0 && cj - i >= 0 && !visited[ci - i][cj - i]) {
                    q.push({ci - i, cj - i});
                    visited[ci - i][cj - i] = true;
                }
            }
        }
        layercounter++;
    }
    cout << "NO";
}