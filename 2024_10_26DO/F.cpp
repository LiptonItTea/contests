#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long mod = 1000000009;

// long long fastpow(long long num, long long pow) {
//     if (pow == 0)
//         return 1;
    
//     if (pow % 2 == 0){
//         long long result = fastpow(num, pow / 2);
//         return ((result % mod) * (result % mod)) % mod;
//     }
//     return (num % mod * fastpow(num, pow - 1) % mod) % mod;
// }

// long long inv(long long num) {
//     return fastpow(num, mod - 2);
// }

// long long sqrt5 = 383008016;

// long long leftk = (((1 + sqrt5) % mod) * inv(2)) % mod;
// long long rightk = (((1 - sqrt5 + mod) % mod) * inv(2)) % mod;

// long long fib(long long n) {
//     return (((fastpow(leftk, n) - fastpow(rightk, n) + mod) % mod) * inv(sqrt5)) % mod;
// }

map<int, long long> fibbDict {{1, 1}, {2, 1}};
int fibbInd = 2;
long long fibbMod(int n) {
    if (n <= fibbInd)
        return fibbDict[n];
    
    for (int i = fibbInd + 1; i <= n; i++){
        fibbDict[i] = (fibbDict[i - 1] + fibbDict[i - 2]) % mod;
    }
    fibbInd = n;
    return fibbDict[n];
}

long long fibbShift(long long a, long long b, int k) {
    int temp1 = (a * fibbMod(k - 2)) % mod;
    int temp2 = (b * fibbMod(k - 1)) % mod;
    return (temp1 + temp2) % mod;
}

int near2(int n) {
    int c = 1;
    while (c < n)
        c <<= 1;
    return c;
}

class ST {
    public:
        int size;
        vector<long long> a;
        vector<long long> b;
        vector<long long> fa;
        vector<long long> fb;
        vector<long long> sumf;
        vector<long long> len;
        vector<bool> push;

        ST (int n) {
            size = near2(n);
            a.reserve(size); b.reserve(2 * size); fa.reserve(2 * size); fb.reserve(2 * size); sumf.reserve(2 * size); 
            len.reserve(2 * size); 
            push.reserve(2 * size);

            for (int i = 0; i < size; i++){
                a.push_back(0);
                b.push_back(0); b.push_back(0);
                fa.push_back(0); fa.push_back(0);
                fb.push_back(0); fb.push_back(0);
                sumf.push_back(0); sumf.push_back(0);
                len.push_back(0); len.push_back(0);
                push.push_back(false); push.push_back(false);
            }
        }

        void build(int v, int l, int r, int currLen){
            if (l == r){
                b[v] = a[l];
                len[v] = currLen;
            }
            else {
                int c = (l + r) / 2;
                build(v * 2 + 1, l, c, currLen / 2);
                build(v * 2 + 2, c + 1, r, currLen / 2);
                b[v] = b[v * 2 + 1] + b[v * 2 + 2];
                len[v] = currLen;
            }
        }

        void build() {
            build(0, 0, size - 1, size);
        }

        void doPush(int v) {
            if (!push[v])
                return;
            
            if (v * 2 + 1 >= 2 * size - 1){
                sumf[v] += fa[v];
                return;
            }

            sumf[v] += fibbShift(fa[v], fb[v], len[v] + 2) - fb[v];
            fa[v * 2 + 1] = fa[v];
            fb[v * 2 + 1] = fb[v];

            fa[v * 2 + 2] = fibbShift(fa[v], fb[v], len[v * 2 + 2] + 1);
            fb[v * 2 + 2] = fibbShift(fa[v], fb[v], len[v * 2 + 2] + 2);

            push[v] = false;
            push[v * 2 + 1] = true;
            push[v * 2 + 2] = true;
        }

        void add(int i, int j, int currA, int currB, int v, int l, int r){
            doPush(v);
            if (j < l || r < i)
                return;
            
            if (i <= l && r <= j){
                push[v] = true;
                fa[v] = currA;
                fb[v] = currB;
                return;
            }

            int c = (l + r) / 2;
            add(i, j, currA, currB, v * 2 + 1, l, c);
            add(i, j, fibbShift(currA, currB, len[v * 2 + 2] + 1), fibbShift(currA, currB, len[v * 2 + 2] + 2), v * 2 + 2, c + 1, r);
        }

        void add(int i, int j) {
            add(i, j, 1, 1, 0, 0, size - 1);
        }

        long long get(int i, int j, int v, int l, int r){
            doPush(v);
            if (j < l || r < i)
                return 0;
            
            if (i <= l && r <= j){
                return b[v] + sumf[v];
            }

            int c = (l + r) / 2;
            return get(i, j, v * 2 + 1, l, c) + get(i, j, v * 2 + 2, c + 1, r);
        }

        long long get(int i, int j){
            return get(i, j, 0, 0, size - 1);
        }
};

int main() {
    int n, m;
    cin >> n >> m;

    ST segtree (n);
    for (int i = 0; i < n; i++){
        cin >> segtree.a[i];
    }

    segtree.build();

    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        l--; r--;

        if (type == 1) {
            segtree.add(l, r);
        }
        else{
            cout << segtree.get(l, r) << "\n";
        }
    }
}