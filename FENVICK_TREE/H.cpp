#include <iostream>
#include <vector>

using namespace std;

struct FenTree {
    vector<int> t;
    int size;

    FenTree (int n) {
        size = n;
        t.assign(n, 0);
    }

    void inc(int i, int value) {
        for (; i < size; i = i | (i + 1))
            t[i] += value;
    }

    int sum(int i) {
        int result = 0;
        for (; i >= 0; i = (i & (i + 1)))
            result += t[i];
        
        return result;
    }
};

int main() {
    FenTree ft (1e6 + 1);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pairs (n, {-1, -1});
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    for (int i = 0; i < m; i++) {
        int cnti;
        cin >> cnti;

        vector<int> allP (cnti, 0);
        for (int j = 0; j < cnti; j++){
            cin >> allP[i];
            ft.inc(allP[i], 1);
        }
        
        for (int j = 0; j < n; )
    }
}