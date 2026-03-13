#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        map<int, int> pos;
        for (int i = 0; i < n; i++){
            cin >> pos[i];
        }
        vector<int> d (n, 0);
        for (int i = 0; i < n; i++)
            cin >> d[i];
        
        int remaining = n;
        for (int i = 0; i < n; i++) {
            int toDelete = d[i] - 1;
            while (pos[toDelete] != 0) {
                int next = pos[toDelete] - 1;
                pos[toDelete] = 0;
                toDelete = next;
                remaining--;
            }

            cout << n - remaining << " ";
        }
        cout << "\n";
    }
}