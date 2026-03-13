#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("trans.in", "r", stdin);
    freopen("trans.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> z (n, 0);
    for (int i = 0; i < n; i++)
        cin >> z[i];
    
    z[0] = 0;
    vector<int> pi (n, 0);
    for (int i = 0; i < n; i++) {
        if (z[i] != 0) {
            for (int j = z[i] - 1; j >= 0; j--) {
                if (pi[i + j] != 0)
                    break;
                pi[i + j] = j + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << pi[i] << " ";
}