#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve2k(vector<int>& f, int n, int k) {
    k *= 2;
    if (k >= n) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += f[i];
        
        return sum;
    }

    int curF = 0;
    int l = 0,
        r = 0;
    
    int maxF = INT_MIN;
    int maxFl = -1;
    int maxFr = -1;

    while (r < n && r < k) {
        curF += f[r++];
    }
    if (curF > maxF) {
        maxF = curF;
        maxFl = l;
        maxFr = r;
    }

    while (r < n) {
        curF += f[r++];
        curF -= f[l++];

        if (curF > maxF) {
            maxF = curF;
            maxFl = l;
            maxFr = r;
        }
    }

    return maxF;
}

int solvekk(vector<int>& f, int n, int k) {
    vector<int> pref (n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + f[i - 1];
    }

    vector<int> dl (n, 0);
    dl[0] = pref[1];
    for (int i = 1; i < n; i++) {
        int curL = max(0, i - k + 1);
        int curR = i;

        int curSum = pref[curR + 1] - pref[curL];
        dl[i] = max(dl[i - 1], curSum); 
    }

    vector<int> dr (n, 0);
    dr[n - 1] = pref[n] - pref[n - 1];
    for (int i = n - 2; i >= 0; i--){
        int curL = i;
        int curR = min(i + k - 1, n - 1);

        int curSum = pref[curR + 1] - pref[curL];
        dr[i] = max(dr[i + 1], curSum);
    }

    int maxF = INT_MIN;
    for (int i = 1; i < n - 1; i++) {
        maxF = max(maxF, dl[i - 1] + dr[i + 1]);
    }
    return maxF;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> f (n, 0);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    cout << max(solve2k(f, n, k), solvekk(f, n, k));
}