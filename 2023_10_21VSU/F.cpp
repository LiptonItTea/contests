#include <iostream>
#include <unordered_map>
#include <format>
#include <iomanip>

using namespace std;

double e = 0.0000001;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    long long* coords = new long long[n];
    long long minCoord = LONG_MAX;
    long long maxCoord = LONG_MIN;
    for (int i = 0; i < n; i++){
        cin >> coords[i];
        minCoord = min(minCoord, coords[i]);
        maxCoord = max(maxCoord, coords[i]);
    }

    long long* vels = new long long[n];
    long long minVelocity = LONG_MAX;
    for (int i = 0; i < n; i++){
        cin >> vels[i];
        minVelocity = min(minVelocity, vels[i]);
    }

    long double l = -1;
    long double r = ((double) (maxCoord - minCoord)) / minVelocity * 2 + 1000;
    long double m = (r + l) / 2.0;
    
    long double maxFalse = -1;
    long double minTrue = r;
    while(true){
        bool good = true;
        long double maxLeft = coords[0] - vels[0] * m;
        long double minRight = coords[0] + vels[0] * m;
        for (int i = 1; i < n; i++){
            maxLeft = max(maxLeft, coords[i] - vels[i] * m);
            minRight = min(minRight, coords[i] + vels[i] * m);
        }
        good = maxLeft <= minRight;
        if(!good)
            maxFalse = max(maxFalse, m);
        else
            minTrue = min(minTrue, m);

        if(abs(minTrue - maxFalse) < e){
            break;
        }

        if(!good){
            l = m;
        }
        else{
            r = m;
        }
        m = (l + r) / 2.0;
    }
    cout << fixed << setprecision(9) << m;
}