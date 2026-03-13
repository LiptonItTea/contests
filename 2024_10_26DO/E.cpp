#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int near2(int n) {
    int c = 1;
    while (c < n)
        c <<= 1;
    return c;
}

class ST {
    public:
        int size;
        vector<long long> b;

        ST (int n) {
            size = near2(n);
            b.reserve(2 * size);
            for (int i = 0; i < size; i++){
                b.push_back(0);
                b.push_back(0);
            }
        }

        void build() {
            build(0, 0, size - 1);
        }

        void add(int i, int j, long long value) {
            add(i, j, value, 0, 0, size - 1);
        }

        long long get(int index) {
            return get(index, 0, 0, size - 1, 0);
        }

    private:
        void build(int v, int l, int r){
            if (l == r){
                b[v] = 0;
            }
            else {
                int c = (l + r) / 2;
                build(v * 2 + 1, l, c);
                build(v * 2 + 1, c + 1, r);
            }
        }

        void add(int i, int j, long long value, int v, int l, int r){
            if (j < l || r < i)
                return;
            
            if (i <= l && r <= j){
                b[v] += value;
                return;
            }

            int c = (l + r) / 2;
            add(i, j, value, v * 2 + 1, l, c);
            add(i, j, value, v * 2 + 2, c + 1, r);
        }

        long long get(int index, int v, int l, int r, long long delta){
            if (l == r)
                return delta + b[v];
            
            int c = (l + r) / 2;
            if (index <= c)
                return get(index, v * 2 + 1, l, c, delta + b[v]);
            return get(index, v * 2 + 2, c + 1, r, delta + b[v]);
        }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);

    int n;
    cin >> n;

    vector<long long> a (n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    //remap
    vector<long long> b (a);
    sort(b.begin(), b.end());
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++){
        um[b[i]] = i;
    }
    for (int i = 0; i < n; i++){
        a[i] = um[a[i]];
    }

    vector<long long> gr (n, 0);
    ST segtree (n);
    for (int i = 0; i < n; i++){
        gr[i] = segtree.get(a[i]);
        if (a[i] - 1 >= 0)
            segtree.add(0, a[i] - 1, 1);
    }

    vector<long long> le (n, 0);
    for (long long i = 0; i < n; i++){
        le[i] = a[i] - (i - gr[i]);
    }

    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += gr[i] * le[i];
    }

    cout << sum;
}