#include <iostream>

using namespace std;

int log3(int n) {
    int i = 0;
    while (n > 0) {
        n /= 3;
        i++;
    }
    return i;
}

int fastPow(int num, int pow) {
    if (pow == 0)
        return 1;
    
    if (pow % 2 == 0) {
        int result = fastPow(num, pow / 2);
        return result * result;
    }
    return fastPow(num, pow - 1);
}

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int l, r;
        cin >> l >> r;

        int result = log3(l) * 2;

        int c = 1;
        int i = 0;
        while (c < l + 1){
            c *= 3;
            i++;
        }

        while (c - 1 <= r) {
            int amount = (c - 1) - max(c / 3, l + 1) + 1;
            int value = i;
            result += amount * value;

            c *= 3;
            i++;
        }
        int amount = min(r - l, r - c/3 + 1);
        int value = i;
        result += amount * value;

        cout << result << "\n";
    }
}