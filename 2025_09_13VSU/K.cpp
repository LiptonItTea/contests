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

bool comp(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

bool sus(int i, int j) {
    return i > j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<pair<int, int>> a (n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), comp);

    int neg_amnt = 0;
    int zer_amnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first < 0)
            neg_amnt++;
        else if (a[i].first == 0)
            zer_amnt++;
        else
            break;
    }

    vector<int> joinzero;
    vector<int> join;
    int remove = -1;
    for (int i = 0; i < n; i++) {
        if (i + 1 == neg_amnt && neg_amnt % 2 != 0){
            remove = a[i].second;
            continue;
        }
        if (a[i].first == 0) {
            // if (remove == -1 && neg_amnt + zer_amnt == n && i + 1 == zer_amnt)// no positive, so we need to have at least one 0
            //     continue; 
            if (neg_amnt + zer_amnt == n) {
                if (remove == -1 && neg_amnt + zer_amnt == i + 1){
                    remove = a[i].second;
                    continue;
                }
                joinzero.push_back(a[i].second);
                continue;
            }
            
            // non zero
            if (remove == -1 && neg_amnt + zer_amnt == i + 1){
                remove = a[i].second;
            }
            joinzero.push_back(a[i].second);
            continue;
        }
        join.push_back(a[i].second);
    }
    sort(joinzero.begin(), joinzero.end());
    sort(join.begin(), join.end());

    for (int i = 0; i < ((int) joinzero.size() - 1); i++)
        cout << "1 " << joinzero[i] + 1 << " " << joinzero[i + 1] + 1 << "\n";
    if (remove != -1)
        cout << "2 " << remove + 1 << "\n";
    for (int i = 0; i < ((int) join.size() - 1); i++)
        cout << "1 " << join[i] + 1 << " " << join[i + 1] + 1<< "\n";
}