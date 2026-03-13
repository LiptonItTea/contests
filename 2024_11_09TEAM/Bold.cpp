#include <iostream>
#include <vector>

using namespace std;

long long area2(int x1, int y1, int x2, int y2, int x3, int y3){
    long long ax = x1 - x2;
    long long ay = y1 - y2;

    long long bx = x1 - x3;
    long long by = y1 - y3;

    //ax ay
    //bx by

    long long area2 = ax * by - bx * ay;
    return abs(area2);
}

int main () {
    int n;
    cin >> n;

    vector<pair<int, int>> coords (n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        coords[i] = {x, y};
    }

    long long totalArea = 0;
    for (int i = 2; i < n; i++){
        int x1 = coords[0].first;
        int y1 = coords[0].second;
        int x2 = coords[i - 1].first;
        int y2 = coords[i - 1].second;
        int x3 = coords[i].first;
        int y3 = coords[i].second;

        long long curTriArea = area2(x1, y1, x2, y2, x3, y3);
        totalArea += curTriArea;
    }

    long long curTriArea = 0;
    int index = -1;
    for (int i = 2; i < n; i++){
        int x1 = coords[0].first;
        int y1 = coords[0].second;
        int x2 = coords[i - 1].first;
        int y2 = coords[i - 1].second;
        int x3 = coords[i].first;
        int y3 = coords[i].second;

        long long delta = area2(x1, y1, x2, y2, x3, y3);
        if((curTriArea + delta) * 2ll > totalArea){
            index = i;
            break;
        }
        curTriArea += delta;
    }

    cout << index << " " << index + 1;
}