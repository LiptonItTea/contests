#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
    int prefx = 0;
    int prefy = 0;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<Point>> point(n, vector<Point>(m));

    // Чтение массива, преобразование и вычисление префиксов одновременно
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            // Если символ '.', то значение 1, иначе 0
            arr[i][j] = (str[j] == '.') ? 1 : 0;

            // Вычисляем `prefx` для текущего элемента
            if (j == 0) {
                point[i][j].prefx = arr[i][j] ? 0 : 1;
            } else {
                point[i][j].prefx = arr[i][j] ? point[i][j - 1].prefx : (point[i][j - 1].prefx + 1);
            }

            // Вычисляем `prefy` для текущего элемента
            if (i == 0) {
                point[i][j].prefy = arr[i][j] ? 0 : 1;
            } else {
                point[i][j].prefy = arr[i][j] ? point[i - 1][j].prefy : (point[i - 1][j].prefy + 1);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;

        if (a == c && b == d) {
            cout << "YES" << endl;
        } else if (a == c) {
            // Проверка горизонтального пути
            if (point[a][min(b, d)].prefx == point[a][max(b, d)].prefx) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (b == d) {
            // Проверка вертикального пути
            if (point[min(a, c)][b].prefy == point[max(a, c)][b].prefy) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            // Проверка возможных диагональных путей
            if (
                (arr[a][d] == 1 && point[a][min(b, d)].prefx == point[a][max(b, d)].prefx &&
                 point[min(a, c)][d].prefy == point[max(a, c)][d].prefy) ||
                (arr[c][b] == 1 && point[c][min(b, d)].prefx == point[c][max(b, d)].prefx &&
                 point[min(a, c)][b].prefy == point[max(a, c)][b].prefy)
            ) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

    solve();
    return 0;
}
