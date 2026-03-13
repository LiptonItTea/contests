#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

struct Item {
    ll a, b;
};

bool sortItems(Item& i1, Item& i2) {
    return i1.b > i2.b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll s;
    cin >> n >> s;

    vector<Item> items (n, {-1, -1});
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        items[i].a = a;
        items[i].b = b;
    }

    sort(items.begin(), items.end(), sortItems);
    
    set<ll> dp {0};
    for (int i = 0; i < n; i++) {
        ll w = items[i].b;
        ll c = items[i].a;

        for (auto it = dp.rbegin(); it != dp.rend(); it++) {
            dp.insert(*it + w);
        }
    }

    for (auto it = dp.begin(); it != dp.end(); it++) {
        cout << *it << " ";
    }
}