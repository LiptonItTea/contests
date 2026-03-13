#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int l = 1;
        int r = 1001;
        map<pair<int, int>, int> memory;

        while (r - l > 1) {
            int a = l + (r - l) / 3;
            int b = l + 2 * (r - l) / 3;
            int area;
            if (memory.find({a, b}) != memory.end()) {
                area = memory[{a, b}];
            }
            else {
                cout << "? " << a << " " << b << endl;
                cin >> area;
                memory[{a, b}] = area;
            }

            if (a * b == area) {
                //right
                l = b + 1;
            }
            else if (a * (b + 1) == area) {
                //center
                l = a + 1;
                r = b + 1;
            }
            else {
                //left
                r = a;
            }
        }
        int area;
        if (memory.find({l, r}) != memory.end()) {
            area = memory[{l, r}];
        }
        else {
            cout << "? " << l << " " << r << endl;
            cin >> area;
        }

        cout << "! ";
        if (area == l * r)
            cout << r + 1;
        else if (area == l * (r + 1))
            cout << r;
        else
            cout << l;
        cout << "\n";
    }
}