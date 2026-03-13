#include <iostream>

using namespace std;

int main(){
    // freopen("knight.in", "r", stdin);
    // freopen("knight.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    long long** field = new long long*[n];
    for (int i = 0; i < n; i++){
        field[i] = new long long[m];
        fill(field[i], field[i] + m, 0);
    }
    field[0][0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(i - 2 >= 0 && j - 1 >= 0){
                field[i][j] += field[i - 2][j - 1];
            }
            if(i - 1 >= 0 && j - 2 >= 0){
                field[i][j] += field[i - 1][j - 2];
            }
        }
    }

    cout << field[n - 1][m - 1];
}