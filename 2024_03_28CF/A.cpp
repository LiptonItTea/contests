#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int** data = new int*[n];
    for (int i = 0; i < n; i++){
        data[i] = new int[3];
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    for (int i = 0; i < n; i++){
        int a = data[i][0],
            b = data[i][1],
            c = data[i][2];
        
        if(a < b && b < c)
            cout << "STAIR\n";
        else if(a < b && b > c)
            cout << "PEAK\n";
        else
            cout << "NONE\n";
    }
}