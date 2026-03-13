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
    int zeros, ones;
    double entropy;
    int in, out;
};

double eps = 1e-8;

vector<int> labels;
vector<vector<int>> links;
vector<Entry> inner;

int counter = 0;
void count_labels(int curr, int prev) {
    inner[curr].in = counter++;
    for (int next : links[curr]) {
        if (next == prev)
            continue;

        count_labels(next, curr);
    }

    for (int next : links[curr]) {
        inner[curr].zeros += inner[next].zeros;
        inner[curr].ones += inner[next].ones;

        double p = ((double) inner[curr].ones) / (inner[curr].zeros + inner[curr].ones);
        if (abs(p) < eps || abs(p - 1) < eps){
            inner[curr].entropy = 0;
            continue;
        }

        inner[curr].entropy = -p * log(p) - (1 - p) * log(1 - p);
    }
    inner[curr].out = counter++;
}

bool comp(Entry &e1, Entry &e2) {
    return e1.entropy < e2.entropy;
}

bool check_parent(Entry &parent, Entry &child) {
    if (parent.in < child.in && parent.out > child.out)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, k;
    cin >> n >> k;
    
    labels.assign(n, 0);
    inner.assign(2 * n - 1, {0, 0, 0.0, 0, 0});
    for (int i = 0; i < n; i++){
        cin >> labels[i];
        
        if (labels[i])
            inner[i].ones = 1;
        else
            inner[i].zeros = 1;
    }
    

    links.assign(2 * n - 1, vector<int> ());
    for (int i = n; i < 2 * n - 1; i++) {
        int l, r;
        cin >> l >> r;

        links[i].push_back(l - 1);
        links[i].push_back(r - 1);
    }

    count_labels(2 * n - 2, -1);

    sort(inner.begin(), inner.end(), comp);
    
    vector<Entry> added;
    double esum = 0;
    for (int i = 0; i < inner.size() && added.size() < k; i++) {
        Entry toadd = inner[i];

        bool bad = false;
        for (Entry e : added) {
            if (check_parent(e, toadd) || check_parent(toadd, e)) {
                bad = true;
                break;
            }
        }

        if (bad)
            continue;

        added.push_back(toadd);
        esum += toadd.entropy;
    }

    cout << esum;
}