#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int l, r;
        cin >> l >> r;

        int lastIndex = 0;
        for (int i = 0; i < 31; i++) {
            int a = l & (1 << i);
            int b = r & (1 << i);

            if (a != b)
                lastIndex = i;
        }

        int x = 0;
        for (int i = lastIndex; i < 31; i++) {
            x += r & (1 << i);
        }
        int y = x - 1;
        int z = l;
        if (z == x || z == y)
            z++;
        if (z == x || z == y)
            z++;
        
        cout << x << " " << y << " " << z << "\n";
    }
}