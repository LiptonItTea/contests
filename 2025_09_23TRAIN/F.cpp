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

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0;
    int i = 0;
    while (s[i] == '1')
        result += a[i++];

    while (i < n) {
        while (i < n - 1 && s[i] == '0' && s[i + 1] == 0)
            i++;

        if (i == n - 1)
            break;
        
        result += a[i];
        int mina = a[i];
        int start = i++;
        while (i < n && s[i] == '1'){
            mina = min(mina, a[i]);
            result += a[i]; 
            i++;
        }
        
        result -= mina;
    }

    cout << result;
}