#include <iostream>
#include <vector>

using namespace std;

int near2(int n) {
    int i = 1;
    while (i < n)
        i <<= 1;
    return i;
}

class DO {
    public:
        vector<int> a;
        vector<int> b;

        DO (int n) {
            n = near2(n);
            a.reserve(n); b.reserve(n);

            for (int i = 0; i < n; i++){
                a.push_back(0);
                b.push_back(0);
                b.push_back(0);
            }
        }

        void build(int v, int l, int r) {
            if (l == r){
                b[v] = a[l];
            }
            else{
                int c = (l + r) / 2;
                build(v * 2 + 1, l, c);
                build(v * 2 + 2, c + 1, r);
                b[v] = b[v * 2 + 1] + b[v * 2 + 2];
            }
        }

        void change(int i, int value, int v, int l, int r){
            if (l == r){
                a[i] = value;
                b[v] = value;
            }
            else{
                int c = (l + r) / 2;
                if (i <= c)
                    change(i, value, v * 2 + 1, l, c);
                else
                    change(i, value, v * 2 + 2, c + 1, r);
                b[v] = b[v * 2 + 1] + b[v * 2 + 2];
            }
        }

        long long sum(int i, int j, int v, int l, int r) {
            if (j < l || r < i)
                return 0;
            
            if (i <= l && r <= j)
                return b[v];
            
            int c = (l + r) / 2;
            return sum(i, j, v * 2 + 1, l, c) + sum(i, j, v * 2 + 2, c + 1, r);
        }
};

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        DO tree (n);

        vector<int> data;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;

            data.push_back(a);
            if(a < i + 1){
                tree.change(i, 1, 0, 0, tree.a.size() - 1);
            }
        }

        long long result = 0;
        for (int i = 0; i < n; i++){
            if (data[i] >= i + 1)
                continue;
            
            int index = data[i] - 2;
            if (index >= 0)
                result += tree.sum(0, index, 0, 0, tree.a.size() - 1);
        }

        cout << result << "\n";
    }
}