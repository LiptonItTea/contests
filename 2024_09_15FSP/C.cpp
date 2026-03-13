#include <iostream>
#include <climits>
#include <string>
#include <queue>

using namespace std;

struct Point3 {
    int x, y, z;
};

int h, n, m;

int bfs(string** plan, bool*** visited, int sz, int sy, int sx){
    queue<Point3> points;
    points.push({sx, sy, sz});

    int currLength = 1;
    while(!points.empty()){
        int currSize = points.size();
        for (int _ = 0; _ < currSize; _++){
            Point3 curr = points.front();
            points.pop();

            int cx = curr.x,
                cy = curr.y,
                cz = curr.z;
            // cout << cx << " " << cy << " " << cz << "\n";
            
            if(plan[cz][cy][cx] == 'U'){
                if(cz == h - 1)
                    return currLength;
                if(cz < h - 1 && !visited[cz + 1][cy][cx] && plan[cz + 1][cy][cx] == 'D'){
                    points.push({cx, cy, cz + 1});
                    visited[cz + 1][cy][cx] = true;
                }
            }
            if(plan[cz][cy][cx] == 'D'){
                if(cz > 0 && !visited[cz - 1][cy][cx] && plan[cz - 1][cy][cx] == 'U'){
                    points.push({cx, cy, cz - 1});
                    visited[cz - 1][cy][cx] = true;
                }
            }

            if(cx > 0 && !visited[cz][cy][cx - 1] && plan[cz][cy][cx - 1] != '#' && plan[cz][cy][cx - 1] != 'E'){
                points.push({cx - 1, cy, cz});
                visited[cz][cy][cx - 1] = true;
            }
            if(cx < m - 1 && !visited[cz][cy][cx + 1] && plan[cz][cy][cx + 1] != '#' && plan[cz][cy][cx + 1] != 'E'){
                points.push({cx + 1, cy, cz});
                visited[cz][cy][cx + 1] = true;
            }
            if(cy > 0 && !visited[cz][cy - 1][cx] && plan[cz][cy - 1][cx] != '#' && plan[cz][cy - 1][cx] != 'E'){
                points.push({cx, cy - 1, cz});
                visited[cz][cy - 1][cx] = true;
            }
            if(cy < n - 1 && !visited[cz][cy + 1][cx] && plan[cz][cy + 1][cx] != '#' && plan[cz][cy + 1][cx] != 'E'){
                points.push({cx, cy + 1, cz});
                visited[cz][cy + 1][cx] = true;
            }
        }
        
        currLength++;
    }

    return 888;
}

int main() {
    // freopen("test.txt", "r", stdin);
    // cout << "start\n";
    cin >> h >> n >> m;

    string** building = new string*[h];
    bool*** visited = new bool**[h];
    for (int i = 0; i < h; i++){
        building[i] = new string[n];
        visited[i] = new bool*[n];
        for (int j = 0; j < n; j++){
            cin >> building[i][j];
            visited[i][j] = new bool[m];
            fill(visited[i][j], visited[i][j] + m, false);
        }
    }
    
    int minPath = INT_MAX;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(building[0][i][j] == 'E'){
                int path = bfs(building, visited, 0, i, j);

                //clear
                for (int k = 0; k < h; k++){
                    for (int l = 0; l < n; l++){
                        fill(visited[k][l], visited[k][l] + m, false);
                    }
                }

                minPath = min(minPath, path);
            }
        }
    }

    cout << minPath;
}