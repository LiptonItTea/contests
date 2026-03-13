#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("invtrans.in", "r", stdin);
    freopen("invtrans.out", "w", stdout);
    
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> pi (n, 0);
    for (int i = 0; i < n; i++)
        cin >> pi[i];
    
    vector<int> z (n, 0);
    // 1
    for (int i = 1; i < n; i++) {
        if (pi[i] != 0) {
            z[i - pi[i] + 1] = pi[i];
        }
    }
    //2
    if (z[1]) {
        for (int i = 1; i < z[1]; i++) {
            z[i + 1] = z[1] - i;
        }
    }

    //3
    for (int i = z[1]; i < n; i++) {
        if (z[i] && !z[i + 1]) {
            int last = i;
            for (int j = 1; j < z[i] && z[i + j] <= z[j]; j++) {
                z[i + j] = min(z[j], z[i] - j);
                last = i + j;
            }
            i = last;
        }
    }

    cout << n << " ";
    for (int i = 1; i < n; i++)
        cout << z[i] << " ";
}