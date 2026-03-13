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

struct Entry {
    int num, ind;
    bool deleted;
};

bool comp_entry(Entry *e1, Entry *e2) {
    if (e1->num != e2->num)
        return e1->num < e2->num;
    return e1->ind < e2->ind;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<Entry*> a (n);
        vector<Entry*> aux (n);
        for (int i = 0; i < n; i++){
            Entry *e = new Entry;
            cin >> e->num;
            e->ind = i;
            e->deleted = false;

            a[i] = e;
            aux[i] = e;
        }
        sort(aux.begin(), aux.end(), comp_entry);

        int result = 0;
        int i1 = 0, i2 = 1; // a
        int j = 0; // aux
        while (i1 < n - 1 || j < n) {
            while (i1 < n - 1 && a[i1]->deleted){
                i1++;
                i2 = max(i2, i1 + 1);
            }
            while (i2 < n && a[i2]->deleted)
                i2++;
            while (j < n && aux[j]->deleted)
                j++;
            if (i1 >= n - 1 && j >= n)
                break;

            // check to delete 2 in a
            if (i2 < n && a[i1]->num == a[i2]->num) {
                a[i1++]->deleted = a[i2++]->deleted = true;
                result++;
                continue;
            }
            
            // otherwise delete min
            aux[j++]->deleted = true;
            result++;
        }

        cout << result << "\n";
    }
}