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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void generate(map<int, int> &counts, map<int, int>::iterator &it, int curr, vector<int> &dest) {
    if (it != counts.end()) {
        advance(it, 1);
        generate(counts, it, curr, dest);
        
        int pow = 1;
        for (int i = 0; i < it->second; i++) {
            pow *= it->first;
            advance(it, 1);
            generate(counts, it, curr * pow, dest);
        }
        advance(it, -1);
        return;
    }
    if (it != counts.begin()){
        dest.push_back(curr);
        advance(it, -1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    vector<int> sieve (100001, 0);
    for (int i = 2; i < sieve.size(); i++)
        if (sieve[i] == 0)
            for (int j = i; j <= sieve.size() - 1; j += i)
                sieve[j] = i;
    sieve[1] = 1;

    vector<vector<int>> divs (sieve.size(), vector<int>());
    for (int i = 2; i < divs.size(); i++) {
        map<int, int> counts;

        int curr = i;
        while (curr != sieve[curr]) {
            counts[sieve[curr]]++;
            curr /= sieve[curr];
        }
        counts[sieve[curr]]++;
        
        auto it = counts.begin();
        generate(counts, it, 1, divs[i]);
    }
    

    int n;
    cin >> n;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1) {
        cout << 1;
        return 0;
    }
    
    vector<int> dp (sieve.size(), 0);
    vector<int> d (sieve.size(), 0);

    int best = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];

        for (int j = 1; j < divs[x].size(); j++) {
            dp[x] = max(dp[x], d[divs[x][j]] + 1);
            best = max(best, dp[x]);
        }

        for (int j = 1; j < divs[x].size(); j++) {
            d[divs[x][j]] = max(dp[divs[x][j]], dp[x]);
        }
    }

    cout << best;
}