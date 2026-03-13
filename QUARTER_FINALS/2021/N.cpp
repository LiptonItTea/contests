#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        int y1 = 0, y2 = 0, y3 = 0;
        int s1 = 0, s2 = 0, s3 = 0;
        for (int i = 0; i < n1; i++){
            string v;
            cin >> v;

            for (int j = 0; j < v.size(); j++) {
                if (v[j] == 'A' || v[j] == 'E' || v[j] == 'I' || v[j] == 'O' || v[j] == 'U' ||
                    v[j] == 'a' || v[j] == 'e' || v[j] == 'i' || v[j] == 'o' || v[j] == 'u')
                    s1++;
                if (v[j] == 'Y' || v[j] == 'y')
                    y1++;
            }
        }
        for (int i = 0; i < n2; i++){
            string v;
            cin >> v;

            for (int j = 0; j < v.size(); j++) {
                if (v[j] == 'A' || v[j] == 'E' || v[j] == 'I' || v[j] == 'O' || v[j] == 'U' ||
                    v[j] == 'a' || v[j] == 'e' || v[j] == 'i' || v[j] == 'o' || v[j] == 'u')
                    s2++;
                if (v[j] == 'Y' || v[j] == 'y')
                    y2++;
            }
        }
        for (int i = 0; i < n3; i++){
            string v;
            cin >> v;

            for (int j = 0; j < v.size(); j++) {
                if (v[j] == 'A' || v[j] == 'E' || v[j] == 'I' || v[j] == 'O' || v[j] == 'U' ||
                    v[j] == 'a' || v[j] == 'e' || v[j] == 'i' || v[j] == 'o' || v[j] == 'u')
                    s3++;
                if (v[j] == 'Y' || v[j] == 'y')
                    y3++;
            }
        }

        if (5 - s1 >= 0 && 5 - s1 <= y1 && 7 - s2 <= y2 && 7 - s2 >= 0 && 5 - s3 <= y3 && 5 - s3 >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}