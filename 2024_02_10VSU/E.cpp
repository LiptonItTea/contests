#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int w, h;
        cin >> w >> h;
        
        long long maxSquare2 = INT_MIN;
        int k;
        long long x1, x2, y1, y2;
        //horizontal
        //y=0
        cin >> k;
        cin >> x1;
        for (int i = 0; i < k - 1; i++){
            cin >> x2;
        }

        maxSquare2 = max(maxSquare2, (x2 - x1) * h);

        //y=h
        cin >> k;
        cin >> x1;
        for (int i = 0; i < k - 1; i++){
            cin >> x2;
        }

        maxSquare2 = max(maxSquare2, (x2 - x1) * h);

        //vertical
        //x=0
        cin >> k;
        cin >> y1;
        for (int i = 0; i < k - 1; i++){
            cin >> y2;
        }

        maxSquare2 = max(maxSquare2, (y2 - y1) * w);

        //x=w
        cin >> k;
        cin >> y1;
        for (int i = 0; i < k - 1; i++){
            cin >> y2;
        }

        maxSquare2 = max(maxSquare2, (y2 - y1) * w);

        cout << maxSquare2 << "\n";
    }
}