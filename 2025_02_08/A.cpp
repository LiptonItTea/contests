#include <iostream>

using namespace std;

int main() {
    int b, k;
    cin >> b >> k;

    int odd = 0;
    int even = 0;
    for (int i = 0; i < k - 1; i++) {
        int a;
        cin >> a;

        if (a % 2 == 0)
            even++;
        else if (b % 2 == 0)
            even++;
        else
            odd++;
    }
    int a;
    cin >> a;
    if (a % 2 == 0)
        even++;
    else
        odd++;

    if (odd % 2 == 0)
        cout << "even";
    else
        cout << "odd";
}