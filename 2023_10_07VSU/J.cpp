#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        if(n == 1){
            cout << "1\n";
            continue;
        }
        if(n == 2){
            cout << "-1\n";
            continue;
        }
        if(n == 3){
            cout << "2 9 7\n" << "4 6 3\n" << "1 8 5\n";
            continue;
        }

        int** matrix = new int*[n];
        for (int i = 0; i < n; i++){
            matrix[i] = new int[n];
        }

        int dir = 1;
        int curNum = 1;
        for (int j = 0; j < 2; j++){
            for (int i = (dir == 1 ? 0 : 1); i < n; i++){
            int x = (dir == 1 ? i : 0);
            int y = (dir == -1 ? i : 0);
            while (x < n && y < n){
                matrix[y][x] = curNum;
                curNum++;
                x++;
                y++;
            }
            }
            dir *= -1;
        }

        int temp = matrix[n - 1][0];
        matrix[n - 1][0] = matrix[0][n - 1];
        matrix[0][n - 1] = temp;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
}