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

    string n;
    cin >> n;
    int source_k = n.size();
    
    vector<int> last (10, -1);
    int count_zero = 0;
    for (int i = 0; i < source_k; i++) {
        last[n[i] - '0'] = i;
        if (n[i] == '0')
            count_zero++;
    }

    int best = source_k - count_zero;
    int curr_sum3 = 0;
    int curr_amn1 = 0;
    int curr_amn2 = 0;
    for (int i = 0; i < source_k; i++) {
        int delta = 0;
        if (n[i] == '0' || n[i] == '2' || n[i] == '5' || n[i] == '7') {
            int curr = -1;
            if (n[i] == '0' && i < last[0]) {
                curr = last[0] - i - 1 + (source_k - last[0] - 1);
            }
            else if (n[i] == '2' && i < last[5]) {
                curr = last[5] - i - 1 + (source_k - last[5] - 1);
                delta = 7;
                curr_sum3 = (curr_sum3 + 7) % 3;
            }
            else if (n[i] == '5' && i < last[0]) {
                curr = last[0] - i - 1 + (source_k - last[0] - 1);
                delta = 5;
                curr_sum3 = (curr_sum3 + 5) % 3;

            }
            else if (n[i] == '7' && i < last[5]) {
                curr = last[5] - i - 1 + (source_k - last[5] - 1);
                delta = 12;
                curr_sum3 = (curr_sum3 + 12) % 3;
            }

            if (curr != -1) {
                if (curr_sum3 % 3 == 1) {
                    if (curr_amn1 > 0)
                        curr++;
                    else if (curr_amn2 > 1)
                        curr += 2;
                    else
                        curr = -1;
                }
                if (curr_sum3 % 3 == 2) {
                    if (curr_amn2 > 0)
                        curr++;
                    else if (curr_amn1 > 1)
                        curr += 2;
                    else
                        curr = -1;
                }
            }

            if (curr != -1) {
                best = min(best, curr);
            }
        }

        curr_sum3 = (curr_sum3 - delta) % 3;
        if (curr_sum3 < 0)
            curr_sum3 += 3;
        curr_sum3 = (curr_sum3 + (n[i] - '0') % 3) % 3;
        curr_amn1 += (n[i] - '0') % 3 == 1;
        curr_amn2 += (n[i] - '0') % 3 == 2;
    }

    cout << best;
}