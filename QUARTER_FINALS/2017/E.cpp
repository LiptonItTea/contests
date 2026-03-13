#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int amnt;
    cin >> amnt;

    string n;
    cin >> n;

    string dec;

    int sum = 0;
    int delta = 0;
    int temp = 0;
    for (int i = 0; i < amnt; i++) {
        int curr = n[i] == '1';
        
        int iter = curr ^ sum; // this digit iteration
        if (delta > 0) {
            while (delta > 0) {
                if (!iter){
                    iter = 1;
                }
                else {
                    iter = 0;
                    temp++;
                }
                delta--;
            }
            delta = temp;
            temp = 0;
        }
        if (curr == 0 && sum == 1)
            delta++;
        
        dec += '0' + iter; //fixing result
        sum ^= iter;
    }

    cout << dec;
}