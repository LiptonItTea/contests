#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int* time = new int[n];
    int globalTime = 0;
    for (int i = 0; i < n; i++){
        int c, t;
        cin >> c >> t;

        time[i] = globalTime + c * t;
        globalTime += c * t;
    }

    for (int _ = 0; _ < m; _++){
        int v;
        cin >> v;

        if(v < time[0]){
            cout << 1 << "\n";
            continue;
        }
        if(time[n - 2] < v && v < time[n - 1]){
            cout << n << "\n";
            continue;
        }

        int l = 0;
        int r = n;
        int m = (r + l) / 2;
        while(true){
            if(time[m] == v){
                break;
            }
            if(time[m - 1] < v && v < time[m]){
                break;
            }

            if(time[m] < v){
                l = m;
            }
            else{
                r = m;
            }
            m = (r + l) / 2;
        }
        cout << m + 1 << "\n";
    }
}