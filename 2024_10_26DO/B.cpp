#include <iostream>
#include <vector>

using namespace std;

int near2(int n) {
    int i = 1;
    while(i < n)
        i *= 2;
    return i;
}

class DO {
    public:
        vector<long long> a;
        vector<long long> bmin;
        vector<long long> bmax;

        DO (int n){
            n = near2(n);
            a.reserve(n); bmin.reserve(2 * n); bmax.reserve(2 * n);
            for (int i = 0; i < n; i++){
                long long j = i + 1;
                long long result = (j * j) % 12345 + (((j * j) % 23456) * j) % 23456;
                a.push_back(result);
                bmin.push_back(0); bmax.push_back(0);
            }
            for (int i = 0; i < n; i++){
                bmin.push_back(0); bmax.push_back(0);
            }
        }

        void build(){
            build(0, 0, a.size() - 1);
        }

        void change(int i, int value){
            change(i, value, 0, 0, a.size() - 1);
        }

        long long getMax(int i, int j){
            return getMax(i, j, 0, 0, a.size() - 1);
        }

        long long getMin(int i, int j){
            return getMin(i, j, 0, 0, a.size() - 1);
        }

    private:
        void build(int v, int l, int r){
            if (l == r){
                bmin[v] = a[l];
                bmax[v] = a[l];
            }
            else{
                int c = (l + r) / 2;
                build(v * 2 + 1, l, c);
                build(v * 2 + 2, c + 1, r);
                bmin[v] = min(bmin[v * 2 + 1], bmin[v * 2 + 2]);
                bmax[v] = max(bmax[v * 2 + 1], bmax[v * 2 + 2]);
            }
        }

        void change(int i, int value, int v, int l, int r){
            if (l == r){
                bmin[v] = value;
                bmax[v] = value;
                a[l] = value;
            }
            else{
                int c = (l + r) / 2;
                if (i <= c)
                    change(i, value, v * 2 + 1, l, c);
                else
                    change(i, value, v * 2 + 2, c + 1, r);
                bmin[v] = min(bmin[v * 2 + 1], bmin[v * 2 + 2]);
                bmax[v] = max(bmax[v * 2 + 1], bmax[v * 2 + 2]); 
            }
        }

        long long getMax(int i, int j, int v, int l, int r){
            if (j < l || r < i)
                return LLONG_MIN;
            
            if (i <= l && r <= j)
                return bmax[v];

            int c = (l + r) / 2;
            return max(getMax(i, j, v * 2 + 1, l, c), getMax(i, j, v * 2 + 2, c + 1, r));
        }
        long long getMin(int i, int j, int v, int l, int r){
            if (j < l || r < i)
                return LLONG_MAX;
            
            if (i <= l && r <= j)
                return bmin[v];

            int c = (l + r) / 2;
            return min(getMin(i, j, v * 2 + 1, l, c), getMin(i, j, v * 2 + 2, c + 1, r));
        }
};

int main() {
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
    int k;
    cin >> k;
    
    DO rvq (100000);
    rvq.build();

    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        
        if(x > 0){
            long long maxq = rvq.getMax(x - 1, y - 1);
            long long minq = rvq.getMin(x - 1, y - 1);
            cout << maxq - minq << "\n";
        }
        else{
            rvq.change(-x - 1, y);
        }
    }
}