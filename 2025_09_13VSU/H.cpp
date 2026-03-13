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

    vector<ll> a (n);
    multiset<ll> all;
    ll suma = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        all.insert(a[i]);
        suma += a[i];
    }

    ll counter = 0;
    vector<ll> res;
    for (int i = 0; i < n; i++) {
        ll guess = suma - a[i];
        if (guess % 2 != 0)
            continue;

        all.erase(all.find(a[i]));
        
        if (all.find(guess / 2) != all.end()) {
            counter++;
            res.push_back(i);
        }
        
        all.insert(a[i]);
    }

    cout << counter << "\n";
    for (int i : res)
        cout << i + 1 << " ";

}