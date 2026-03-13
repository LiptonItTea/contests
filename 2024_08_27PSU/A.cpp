#include <iostream>

using namespace std;

int main (){
    freopen("a-heap.in", "r", stdin);
    freopen("a-heap.out", "w", stdout);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        long long n, k;
        cin >> n >> k;

        if((n - 1ll) % (k + 1ll) == 0ll){
            cout << 0ll << "\n";
            continue;
        }

        long long i = (n - 1ll) / (k + 1ll);
        cout << n - (i * k + i + 1ll) << "\n";
    }
}