#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, d;
        cin >> n >> d;

        int xmin = sqrt(d) - 1;
        bool found = false;

        int prevDays = xmin + ceil(d / (xmin + 1.0));
        int prevX = xmin;
        for (int x = xmin + 1; x <= 1000000000; x++){
            if(prevDays <= n){
                found = true;
                break;
            }

            int currDays = x + ceil(d / (x + 1.0));
            if(currDays > prevDays){
                break;
            }
            prevDays = currDays;
            prevX = x;
        }
        if(found){
            cout << "YES\n";
            continue;
        }
        prevDays = xmin + ceil(d / (xmin + 1.0));
        prevX = xmin;
        for (int x = xmin - 1; x >= 0; x--){
            if(prevDays <= n){
                found = true;
                break;
            }

            int currDays = x + ceil(d / (x + 1.0));
            if(currDays > prevDays){
                break;
            }
            prevDays = currDays;
            prevX = x;
        }
        if(found){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}