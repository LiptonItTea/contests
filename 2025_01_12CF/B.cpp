#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>

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

        vector<int> a (n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b (n, 0);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int delta = -1;
        int maxNegDelta = INT_MIN;

        bool positive = false;
        bool neutral = false;
        bool bad = false;
        for (int i = 0; i < n; i++) {
            if (b[i] - a[i] > 0) {
                delta = b[i] - a[i];
                if (positive || neutral) {
                    bad = true;
                    break;
                }

                positive = true;
                continue;
            }
            if (b[i] - a[i] == 0) {
                if (positive){
                    bad = true;
                    break;
                }

                neutral = true;

            }
            
            maxNegDelta = max(maxNegDelta, b[i] - a[i]);
        }

        if (bad){
            cout << "NO\n";
            continue;
        }
        
        if (delta != -1 && delta > abs(maxNegDelta))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}