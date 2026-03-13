#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> a (n, 0);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    vector<ll> sums (n, 0);
    sums[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sums[i] = sums[i + 1] + a[i];
    }

    ll total = 0;
    for (int i = 0; i < n; i++) {
        
    }
    
    cout << total;
}