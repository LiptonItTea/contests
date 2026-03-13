#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> coordX (n);
    vector<int> coordY (n);
    for (int i = 0; i < n; i++){
        cin >> coordX[i] >> coordY[i];
    }
    sort(coordX.begin(), coordX.end());
    sort(coordY.begin(), coordY.end());

    cout << coordX[(n - 1) / 2] << " " << coordY[(n - 1) / 2];
}