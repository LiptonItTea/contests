#include <iostream>
#include <set>

using namespace std;

int main () {
    set<int> all;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        all.insert(num);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int num;
        cin >> num;
        
        all.insert(num);
    }

    cout << all.size();
}