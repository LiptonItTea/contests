#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    string file;
    cin >> file;

    int result = 0;
    int l = -1;
    int r = 0;
    while (r < n) {
        if(file[r] != 'x') {
            if (r - l - 1 >= 3) {
                result += r - l - 3;
            }
            l = r;
        }
        r++;
    }
    if (r - l - 1 >= 3) {
        result += r - l - 3;
    }

    cout << result;
}