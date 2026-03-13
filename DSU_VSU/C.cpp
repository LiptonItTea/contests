#include <iostream>
#include <queue>

using namespace std;

// class DSU {
//     public:
//         int n;
//         int** parents;

//         DSU (int k, int n, int m){
//             parents = new int*[k * n * m];
//             for (int i = 0; i < k * n * m; i++){
//                 parents[i] = new int[2];
//                 parents[i][0] = i;
//                 parents[i][1] = 1;
//             }
//         }

//         int fnd(int u){
//             return (parents[u][0] == u) ? (u) : (parents[u][0] = fnd(parents[u][0]));
//         }

//         int uni(int u, int v){
//             int parentU = fnd(u);
//             int parentV = fnd(v);

//             parents[parentU][0] = parentV;
//             parents[parentV][1] = parents[parentU][1];
//         }
// };

int main(){
    int k, n, m;
    cin >> k >> n >> m;

    // DSU dsu (k, n, m);

    string** data = new string*[k];
    for (int i = 0; i < k; i++){
        data[i] = new string[n];
        for (int j = 0; j < n; j++){
            cin >> data[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    bool*** visited = new bool**[k];
    for (int i = 0; i < k; i++){
        visited[i] = new bool*[n];
        for (int j = 0; j < n; j++){
            visited[i][j] = new bool[m];
            for (int l = 0; l < m; l++){
                visited[i][j][l] = false;
            }
        }
    }
    visited[0][x - 1][y - 1] = true;

    //bfs
    queue<pair<int, pair<int, int>>> cellsQueue;
    cellsQueue.push({0, {x - 1, y - 1}});
    int counter = 1;
    while(!cellsQueue.empty()){
        pair<int, pair<int, int>> cell = cellsQueue.front();
        cellsQueue.pop();

        int currK = cell.first;
        int currX = cell.second.first;
        int currY = cell.second.second;

        if(currK > 0 && !visited[currK - 1][currX][currY] && data[currK - 1][currX][currY] == '.'){
            cellsQueue.push({currK - 1, {currX, currY}});
            visited[currK - 1][currX][currY] = true;
            counter++;
        }
        if(currK < k - 1 && !visited[currK + 1][currX][currY] && data[currK + 1][currX][currY] == '.'){
            cellsQueue.push({currK + 1, {currX, currY}});
            visited[currK + 1][currX][currY] = true;
            counter++;
        }

        if(currX > 0 && !visited[currK][currX - 1][currY] && data[currK][currX - 1][currY] == '.'){
            cellsQueue.push({currK, {currX - 1, currY}});
            visited[currK][currX - 1][currY] = true;
            counter++;
        }
        if(currX < n - 1 && !visited[currK][currX + 1][currY] && data[currK][currX + 1][currY] == '.'){
            cellsQueue.push({currK, {currX + 1, currY}});
            visited[currK][currX + 1][currY] = true;
            counter++;
        }

        if(currY > 0 && !visited[currK][currX][currY - 1] && data[currK][currX][currY - 1] == '.'){
            cellsQueue.push({currK, {currX, currY - 1}});
            visited[currK][currX][currY - 1] = true;
            counter++;
        }
        if(currY < m - 1 && !visited[currK][currX][currY + 1] && data[currK][currX][currY + 1] == '.'){
            cellsQueue.push({currK, {currX, currY + 1}});
            visited[currK][currX][currY + 1] = true;
            counter++;
        }
    }

    cout << counter;
}