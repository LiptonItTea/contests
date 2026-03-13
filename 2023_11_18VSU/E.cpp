#include <iostream>

using namespace std;

int main(){
    int n, m;
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> m;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++){
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    // 1 - create matrix
    int** solve = new int*[n];
    for (int i = 0; i < n; i++){
        solve[i] = new int[m];
    }
    solve[0][0] = matrix[0][0];
    
    //2 - initialize extreme lines
    //vertical
    for (int i = 1; i < n; i++){
        solve[i][0] = solve[i - 1][0] + matrix[i][0];
    }
    //horizontal
    for (int j = 1; j < m; j++){
        solve[0][j] = solve[0][j - 1] + matrix[0][j];
    }
    //3 - solve the least
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            solve[i][j] = max(solve[i - 1][j], solve[i][j - 1]) + matrix[i][j];
        }
    }
    char* path = new char[n + m - 2];
    int y = n - 1,
        x = m - 1;
    int c = n + m - 2 - 1;

    //cout << "___________________________" << endl;

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << solve[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //cout << "___________________________" << endl;
    
    while(x != 0 || y != 0){
        if(x == 0){
            path[c--] = 'D';
            y--;
        }
        else if(y == 0){
            path[c--] = 'R';
            x--;
        }
        else if(solve[y - 1][x] > solve[y][x - 1]){
            path[c--] = 'D';
            //cout << "at " << x << " " << y << " choosed " << 'D' << endl;
            y--;
        } 
        else{
            path[c--] = 'R';
            //cout << "at " << x << " " << y << " choosed " << 'R' << endl;
            x--;
        }
    }
    cout << solve[n - 1][m - 1] << "\n";
    for (int i = 0; i < n + m - 2; i++){
        cout << path[i];
    }
}