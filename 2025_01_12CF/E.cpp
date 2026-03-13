#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Entry {
    int a, b;
};

bool compare_what(Entry& e1, Entry& e2) {
    if (e1.a < e1.b) {
        if (e2.a < e2.b)
            return e1.a < e2.a;
        else return false;
    }
    else if (e1.a == e1.b) {
        if (e2.a < e2.b)
            return true;
        else if (e2.a == e2.b)
            return e1.a < e2.a;
        else return false;
    }
    else {
        if (e2.a < e2.b)
            return true;
        else if (e2.a == e2.b)
            return true;
        else return e1.a > e2.b;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<Entry> c (n, {0, 0});
        for (int i = 0; i < n; i++) 
            cin >> c[i].a >> c[i].b;
        sort(c.begin(), c.end(), compare_what);

        vector<int> prefa (n + 1, 0);
        vector<int> prefb (n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            prefa[i] = prefa[i - 1] + c[i - 1].a;
            prefb[i] = prefb[i - 1] + c[i - 1].b;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int crit = prefb[i - 1] + (prefb[n] - prefb[i]);
            if (crit < prefa[n])
                continue;
            
            
        }
    }
}