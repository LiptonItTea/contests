#include <iostream>
#include <vector>

using namespace std;

int count2(int n){
    int i = 1;
    int c = 0;
    while(i < n){
        i *= 2;
        c++;
    }
    return c;
}

class DO {
    public:
        vector<long long> a;
        vector<long long> b;

        DO (int n) {
            n = (1 << count2(n));
            a.reserve(n); b.reserve(2 * n);

            for (int i = 0; i < n; i++){
                a.push_back(0);
                b.push_back(0);
            }
            for (int i = 0; i < n; i++)
                b.push_back(0);
        }

        void build(){
            build(1, 0, a.size() - 1);
        }

        void change(long long i, long long value){
            change(i, value, 1, 0, a.size() - 1);
        }

        long long sum(long long i, long long j){
            return sum(i, j, 1, 0, a.size() - 1);
        }
    
    private:
        void build(long long v, long long l, long long r){
            if (l == r){
                b[v] = a[l];
            }
            else{
                long long c = (l + r) / 2;
                build(2 * v, l, c);
                build(2 * v + 1, c + 1, r);
                b[v] = b[2 * v] + b[2 * v + 1];
            }
        }

        void change(long long i, long long value, long long v, long long l, long long r){
            if(l == r){
                b[v] = value;
                a[l] = value;
            }
            else{
                long long c = (l + r) / 2;
                if (i <= c)
                    change(i, value, v * 2, l, c);
                else
                    change(i, value, v * 2 + 1, c + 1, r);
                b[v] = b[v * 2] + b[v * 2 + 1];
            }
        }

        long long sum(long long i, long long j, long long v, long long l, long long r){
            if(j < l || r < i){
                return 0;
            }

            if(i <= l && r <= j){
                return b[v];
            }

            long long c = (l + r) / 2;
            return sum(i, j, v * 2, l, c) + sum(i, j, v * 2 + 1, c + 1, r);
        }
};

int main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    DO ltr (n);

    for (int i = 0; i < k; i++){
        char type; int v1, v2;
        cin >> type >> v1 >> v2;

        if (type == 'A'){
            ltr.change(v1 - 1, v2);
        }
        else {
            cout << ltr.sum(v1 - 1, v2 - 1) << "\n";
        }
    }
}