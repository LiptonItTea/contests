#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string* data = new string[n];
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }
    if(data[n * 2 / 3][m / 2] == '*'){
        cout << 0;
        return 0;
    }
    int sy = n * 2 / 3;
    int sx = m / 2;

    int fx = -1, fy = -1;
    for (int r = 1; r < max(n, m); r++){
        int lx = max(0, sx - r);
        int rx = min(sx + r, m - 1);
        int uy = max(0, sy - r);
        int dy = min(sy + r, n - 1);
        //up
        for (int x = lx; x <= rx; x++){
            if(data[uy][x] == '*'){
                fx = x;
                fy = uy;
                cout << abs(fx - sx) + abs(fy - sy);
                return 0;
            }
        }
        //right
        for (int y = uy; y <= dy; y++){
            if(data[y][rx] == '*'){
                fx = rx;
                fy = y;
                cout << abs(fx - sx) + abs(fy - sy);
                return 0;
            }
        }
        //down
        for (int x = lx; x <= rx; x++){
            if(data[dy][x] == '*'){
                fx = x;
                fy = dy;
                cout << abs(fx - sx) + abs(fy - sy);
                return 0;
            }
        }
        //left
        for (int y = uy; y <= dy; y++){
            if(data[y][lx] == '*'){
                fx = lx;
                fy = y;
                cout << abs(fx - sx) + abs(fy - sy);
                return 0;
            }
        }
    }
}