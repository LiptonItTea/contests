#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>   

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;

        string path;
        cin >> path;

        vector<vector<long long>> field (n, vector<long long> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
            }
        }

        int x = 0,
            y = 0;
        for (int k = 0; k < path.size(); k++) {
            long long curSum = 0;

            if (path[k] == 'D') {
                for (int j = 0; j < m; j++) {
                    if (j == x)
                        continue;
                    
                    curSum += field[y][j];
                }
                field[y][x] = -curSum;
                y++;
            }
            else {
                for (int i = 0; i < n; i++) {
                    if (i == y)
                        continue;
                    
                    curSum += field[i][x];
                }
                field[y][x] = -curSum;
                x++;
            }
        }
        long long curSum = 0;
        if (path[path.size() - 1] == 'D') {
            for (int j = 0; j < m; j++) {
                if (j == x)
                    continue;
                
                curSum += field[y][j];
            }
            field[y][x] = -curSum;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (i == y)
                    continue;
                
                curSum += field[i][x];
            }
            field[y][x] = -curSum;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << field[i][j] << " ";
            }
            cout << "\n";
        }
    }
}