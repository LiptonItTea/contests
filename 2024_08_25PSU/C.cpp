#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int** coords = new int*[n];
    for (int i = 0; i < n; i++){
        coords[i] = new int[2];
        cin >> coords[i][0];
        cin >> coords[i][1];
    }

    
    int prevX = -1;
    int lowBound = -1;
    int highBound = -1;
    for (int i = 0; i < n; i++){
        int x = coords[i][0];
        int y = coords[i][1];

        if(x < prevX){
            cout << "NO";
            return 0;
        }

        if(x != prevX){
            prevX = x;
            lowBound = highBound = y;
            continue;
        }

        if(lowBound <= y && y <= highBound){
            cout << "NO";
            return 0;
        }
        lowBound = min(lowBound, y);
        highBound = max(highBound, y);
    }
    cout << "YES";
}