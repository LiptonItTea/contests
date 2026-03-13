#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int  _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<int> a (n, -1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        vector<vector<int>> prefsInv (n, vector<int> (n + 1, 0));
        vector<vector<int>> prefsGood (n, vector<int> (n + 1, 0));
        int totalInv = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                prefsInv[i][j + 1] = prefsInv[i][j];
                prefsGood[i][j + 1] = prefsGood[i][j];
                
                if (a[i] > a[j]){
                    prefsInv[i][j + 1]++;
                    totalInv++;
                }
                if (a[i] < a[j])
                    prefsGood[i][j + 1]++;
            }
        }

        int bestTotalInv = totalInv;
        int bestl = 0,
            bestr = 0;
        for (int size = 2; size <= n; size++) {
            for (int i = 0; i < n - (size - 1); i++) {
                int inverted = prefsInv[i][i + size];
                int good = prefsGood[i][i + size];

                int delta = good - inverted;

                if (bestTotalInv > totalInv + delta) {
                    bestTotalInv = totalInv + delta;
                    bestl = i;
                    bestr = i + size - 1;
                }
            }
        }

        cout << bestl + 1 << " " << bestr + 1 << '\n';
    }
}