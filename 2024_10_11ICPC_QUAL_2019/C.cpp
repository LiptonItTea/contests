#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    // for (int i = 1; i < 50; i++){
    //     for (int j = 1; j < 50; j++){
    //         cout << (i + j - 2) % 7 + 1 << " ";
    //     }
    //     cout << "\n";
    // }
    cout << (x + y - 2) % 7 + 1;
}