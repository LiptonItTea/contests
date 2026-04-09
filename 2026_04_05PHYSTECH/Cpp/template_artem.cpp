#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize ("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define ld long double
#define ull unsigned ll
#define u32 uint32_t

//#define DEBUG
//#define TIMER

constexpr ld PI = acos(-1);
#define inf 10'000'000'000
#define minf -10'000'000'000
#define MOD 1'000'000'007
#define EPS 1e-12
#define all(x) x.begin(),x.end()
#define print(x) for(auto element:x) cout << element << " ";
#define endl "\n"
#define pii pair<int, int>


bool comp(pii a, pii b) {
    return a.second < b.second;
}

void solution() {
    int n;
    cin >> n;
    vector<pii > a(n);
    for (int i = 0; i < n; i++) {

        a[i].first = i + 1;
        cin >> a[i].second;
    }
    sort(all(a), comp);
    vector<int> norm(n);
    for (int i = 0; i < n; i++) {
        norm[i] = a[i].first;
    }
    vector<int> mx(n), mn(n);
    if (n & 1) {
        mx[0] = norm[n - 1];
        for (int i = 1; i < n; i++) {
            mx[i] = norm[i - 1];
        }


        for (int i = 0; i < n - 2; i++) {
            mn[i] = norm[i];
        }
        mn[n - 2] = norm[n - 1];
        mn[n - 1] = norm[n - 2];

    }else {
        mx[0] = norm[1];
        mx[1] = norm[0];
        for (int i = 2; i < n; i++) {
            mx[i] = norm[i];
        }

        reverse(all(norm));
        mn = norm;
    }

    print(mn);
    cout << endl;
    print(mx);
}


int main() {
    cout << fixed << setprecision(0);
#ifdef TIMER
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solution();
        //cout << endl;
    }
#ifdef TIMER
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
        - _clock_start).count() << " ms." << endl;
#endif
}
