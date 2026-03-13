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
    while(r - l > 2) {
        int size = (r - l) / 3;

        cout << "? " << size << " " << size << "\n"; cout.flush();
        for (int i = l; i < l + size; i++)
            cout << i + 1 << " ";
        cout << "\n"; cout.flush();
        for (int i = l + size; i < l + size * 2; i++)
            cout << i + 1 << " ";
        cout << "\n"; cout.flush();

        char res;
        cin >> res;

        if (res == '=') {
            l = l + size * 2;
        }
        else if (res == '>'){
            r = l + size;
        }
        else{
            r = l + size * 2;
            l = l + size;
        }
    }

    if (r - l == 2){
        cout << "? " << 1 << " " << 1 << "\n" << l + 1 << "\n" << r << "\n"; cout.flush();
        
        char res;
        cin >> res;

        if (res == '>')
            cout << "! " << l + 1 << "\n";
        else
            cout << "! " << r << "\n";
        cout.flush();
        return 0;
    }

    cout << "! " << l + 1 << "\n";
    cout.flush();
}