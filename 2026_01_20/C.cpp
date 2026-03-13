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

    list<int> result {0};
    auto it = result.begin();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R')
            it++;
        
        result.insert(it, i + 1);
        it--;
    }
    for (int i : result) {
        cout << i << " ";
    }
}