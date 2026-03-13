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

    int n;
    cin >> n;

    vector<int> a (n, 0);
    multiset<int> right;
    set<int> left;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
        right.insert(a[i]);
    }
    
    int mexl = 0;
    int mexr = -1;
    int prev = -1;
    for (auto it = right.begin(); it != right.end(); it++) {
        if (prev == -1){
            if (*it > 0){
                mexr = 0;
                break;
            }

            prev = *it;
            continue;
        }

        if (*it - prev > 1){
            mexr = prev + 1;
            break;
        }
        prev = *it;
    }
    if (mexr == -1)
        mexr = prev + 1;

    for (int i = 0; i < n; i++) {
        left.insert(a[i]);

        auto it = left.lower_bound(mexl);
        if (it != left.end() && *it - mexl == 0) {
            int prev = mexl;
            while (it != left.end() && *it - prev <= 1)
                prev = *(it++);
            
            mexl = prev + 1;
        }

        cout << mexr + mexl << " ";

        right.erase(right.find(a[i]));
        if (right.find(a[i]) == right.end() && a[i] < mexr) {
            mexr = a[i];
        }
    }
}