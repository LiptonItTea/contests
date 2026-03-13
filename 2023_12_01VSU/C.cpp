#include <iostream>
#include <iomanip>

using namespace std;

int area2(int x1, int y1, int x2, int y2){
    int det = x1 * y2 - y1 * x2;
    return det;
}

int main(){
    freopen("area.in", "r", stdin);
    freopen("area.out", "w", stdout);
    int n;
    cin >> n;

    int** coords = new int*[n];
    for (int i = 0; i < n; i++){
        coords[i] = new int[2];
        cin >> coords[i][0] >> coords[i][1];
    }

    int areaSum = 0;
    for (int i = 0; i < n - 1; i++){
        int x1 = coords[i][0];
        int y1 = coords[i][1];
        int x2 = coords[i + 1][0];
        int y2 = coords[i + 1][1];

        areaSum += area2(x1, y1, x2, y2);
    }
    int x1 = coords[n - 1][0];
    int y1 = coords[n - 1][1];
    int x2 = coords[0][0];
    int y2 = coords[0][1];
    areaSum += area2(x1, y1, x2, y2);
    areaSum = abs(areaSum);

    cout << fixed << ((double) areaSum) / 2;
}