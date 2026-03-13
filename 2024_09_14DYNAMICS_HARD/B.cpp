#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> field (n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> field[i][j];
        }
    }

    vector<vector<int>> minField (n, vector<int> (m, INT_MAX));
    minField[0][0] = field[0][0];

    queue<pair<int, int>> coords;
    coords.push({0, 0});
    while(!coords.empty()){
        pair<int, int> p = coords.front();
        coords.pop();

        int y = p.first;
        int x = p.second;

        if(y < n - 1 && max(minField[y][x], field[y + 1][x]) < minField[y + 1][x]){
            minField[y + 1][x] = max(minField[y][x], field[y + 1][x]);
            coords.push({y + 1, x});
        }
        if(x > 0 && max(minField[y][x], field[y][x - 1]) < minField[y][x - 1]){
            minField[y][x - 1] = max(minField[y][x], field[y][x - 1]);
            coords.push({y, x - 1});
        }
        if(x < m - 1 && max(minField[y][x], field[y][x + 1]) < minField[y][x + 1]){
            minField[y][x + 1] = max(minField[y][x], field[y][x + 1]);
            coords.push({y, x + 1});
        }
    }

    cout << minField[n - 1][m - 1];
}