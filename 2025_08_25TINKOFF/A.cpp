#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    string x;
    cin >> x;
    int count0 = 0;
    for (int i = 0; i < 4; i++)
        if (x[i] == '0')
            count0++;

    sort(x.begin(), x.end());

    string nx = "    ";
    nx[0] = x[count0];
    for (int i = 1; i < count0 + 1; i++)
        nx[i] = '0';
    for (int i = count0 + 1; i < 4; i++)
        nx[i] = x[count0 + (i - count0)];
    
    cout << nx;
}