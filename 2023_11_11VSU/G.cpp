#include <iostream>

using namespace std;

long long dist(long long x1, long long y1, long long x2, long long y2){
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

long long getR2(long long x1, long long y1, long long x2, long long y2, long long r1, long long** coords, long long n){
    long long maxDist = 0;
    for (long long i = 0; i < n; i++){
        long long curX = coords[i][0],
            curY = coords[i][1];

        if(dist(x1, y1, curX, curY) <= r1){
            continue;
        }

        long long d = dist(x2, y2, curX, curY);
        maxDist = max(maxDist, d);
    }
    return maxDist;
}

int main(){
    long long n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    long long** coords = new long long*[n];
    for (long long i = 0; i < n; i++){
        coords[i] = new long long[2];
        cin >> coords[i][0] >> coords[i][1];
    }

    long long r1r2 = getR2(x1, y1, x2, y2, 0, coords, n);
    for (long long i = 0; i < n; i++){
        long long r1 = dist(x1, y1, coords[i][0], coords[i][1]);
        long long r2 = getR2(x1, y1, x2, y2, r1, coords, n);

        r1r2 = min(r1r2, r1 + r2);
    }
    cout << r1r2;
}