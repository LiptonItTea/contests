#include <iostream>
#include <vector>

using namespace std;

struct FenTree {
    int size;
    vector<int> t;

    FenTree(int _size) {
        size = _size;
        t.assign(size, 0);
    };

    int sum(int i) {
        int result = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            result += t[i];
        return result;
    }

    void inc(int i, int delta) {
        for (; i < size; i = i | i + 1)
            t[i] += delta;
    }
};

int main() {
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);

    int size = 1e6;
    FenTree ft (size);
    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        result += ft.sum(size - 1) - ft.sum(a);
        ft.inc(a, 1);
    }

    cout << result;
}