#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int near2(int n) {
    int c = 1;
    while (c < n)
        c <<= 1;
    return c;
}

class DO {
    public:
        vector<long long> a;
        vector<long long> b;
        vector<long long> lazy;

        DO (int n) {
            n = near2(n);
            a.reserve(n); b.reserve(2 * n); lazy.reserve(2 * n);

            for (int i = 0; i < n; i++){
                a.push_back(LLONG_MAX);
                b.push_back(LLONG_MAX); lazy.push_back(0);
                b.push_back(LLONG_MAX); lazy.push_back(0);
            }
        }

        void build() {
            build(0, 0, a.size() - 1);
        }

        void change(int i, int j, long long value){
            change(i, j, value, 0, 0, a.size() - 1);
        }

        long long findmin(int i, int j){
            return findmin(i, j, 0, 0, a.size() - 1);
        }

    private:
        void build(int v, int l, int r){
            if(l == r) {
                b[v] = a[l];
            }
            else {
                int c = (l + r) / 2;
                build(v * 2 + 1, l, c);
                build(v * 2 + 2, c + 1, r);
                b[v] = min(b[v * 2 + 1], b[v * 2 + 2]);
            }
        }
        
        void push(int v){
            if (lazy[v] == 0)
                return;

            if (v * 2 + 1 >= b.size())
                return;
            
            b[v] += lazy[v];
            //push
            lazy[2 * v + 1] += lazy[v];
            lazy[2 * v + 2] += lazy[v];
            lazy[v] = 0;
        }

        void change(int i, int j, long long value, int v, int l, int r){
            push(v);
            if (j < l || r < i)
                return;
            
            if(i <= l && r <= j){
                lazy[v] += value;
                return;
            }

            int c = (l + r) / 2;
            change(i, j, value, v * 2 + 1, l, c);
            change(i, j, value, v * 2 + 2, c + 1, r);
            b[v] = min(b[v * 2 + 1] + lazy[v * 2 + 1], b[v * 2 + 2] + lazy[v * 2 + 2]);
        }

        long long findmin(int i, int j, int v, int l, int r){
            push(v);
            if (j < l || r < i)
                return LLONG_MAX;
            
            if(i <= l && r <= j){
                return b[v] + lazy[v];
            }

            int c = (l + r) / 2;
            
            return min(findmin(i, j, v * 2 + 1, l, c), findmin(i, j, v * 2 + 2, c + 1, r));
        }
};

int main() {
    int n;
    cin >> n;

    DO tree (n);
    for (int i = 0; i < n; i++){
        cin >> tree.a[i];
    }
    tree.build();

    int m;
    cin >> m;
    cin.get();
    for (int i = 0; i < m; i++){
        string result;
        getline(cin, result);

        stringstream ss (result);
        int c = count(result.begin(), result.end(), ' ');

        string sl, sr;
        ss >> sl >> sr;
        int l = stoi(sl),
            r = stoi(sr);

        if (c == 2) {
            string sv;
            ss >> sv;

            int v = stoi(sv);

            if (r < l){
                tree.change(l, n - 1, v);
                tree.change(0, r, v);
            }
            else{
                tree.change(l, r, v);
            }
        }
        else {
            long long found = LLONG_MAX;
            if(r < l) {
                found = min(found, tree.findmin(l, n - 1));
                found = min(found, tree.findmin(0, l));
            }
            else {
                found = tree.findmin(l, r);
            }
            cout << found << "\n";
        }
    }
}