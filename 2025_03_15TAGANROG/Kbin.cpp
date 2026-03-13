#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 0;
    int r = n;
    int c;
    while(r - l > 1) {
        if ((r - l) % 2 != 0)
            r--;
        
        c = (l + r) / 2;

        cout << "? " << c - l << " " << r - c << "\n"; cout.flush();
        for (int i = l; i < c; i++)
            cout << i + 1 << " ";
        cout << "\n"; cout.flush();
        for (int i = c; i < r; i++)
            cout << i + 1 << " ";
        cout << "\n"; cout.flush();

        char res;
        cin >> res;

        if (res == '=') {
            cout << "! " << r + 1;
            cout.flush();
            return 0;
        }

        if (res == '>'){
            r = c;
        }
        else{
            l = c;
        }
    }

    if (r - l <= 1)
        cout << "! " << l + 1;
    else
        cout << "! " << c + 1;
    cout.flush();
}