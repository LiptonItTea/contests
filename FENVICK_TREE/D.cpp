#include <iostream>
#include <vector>

using namespace std;

struct FenTree {
    vector<long long> t;
    int size;

    FenTree(int n) {
        size = n;
        t.assign(size, 0);
    }

    void inc(int i, long long value) {
        for (; i < size; i = i | i + 1)
            t[i] += value;
    }

    long long sum(int i) {
        long long result = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            result += t[i];
        
        return result;
    }
};

int main() {
    freopen("segmentupdate.in", "r", stdin);
    freopen("segmentupdate.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> source (n, 0);
    for (int i = 0; i < n; i++)
        cin >> source[i];
    
    FenTree ft (n + 1);

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--; r--;

            ft.inc(l, x);
            ft.inc(r + 1, -x);
        }
        else {
            int i;
            cin >> i;
            i--;

            cout << source[i] + ft.sum(i) << "\n";
        }
    }
}