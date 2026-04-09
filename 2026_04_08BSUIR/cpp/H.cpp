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

//constexpr ld PI = acos(-1);
#define inf 10'000'000'000
#define minf -10'000'000'000
#define MOD 1'000'000'007
#define EPS 1e-12
#define all(x) x.begin(),x.end()
#define print(x) for(auto element:x) cout << element << " ";
#define endl "\n"
#define pii pair<int, int>


ld square(ld a) {
    return a * a;
}

struct Point {
    ld x, y, z;
};

ld abs(const Point &a) {
    return sqrtl(square(a.x) + square(a.y) + square(a.z));
}

Point operator -(Point &a, Point &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

void solution() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x;
        cin >> points[i].y;
        cin >> points[i].z;
    }


    ld ans = 1e9L;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = min(ans, (abs(points[i] - points[j]) + abs(points[i] - points[0]) + abs(points[j] - points[0])) / 2);
        }
    }

    // Point vec1 = {1e9, 1e9, 1e9};
    // Point vec2 = vec1;
    //
    // ld len1 = 1e9;
    // ld len2 = len1;
    //
    // for (int i = 1; i < n; i++) {
    //     ld cur_len = len(points[0], points[i]);
    //     if (cur_len < len1) {
    //         len2 = len1;
    //         vec2 = vec1;
    //
    //         len1 = cur_len;
    //         vec1 = points[i];
    //     } else {
    //         if (cur_len < len2) {
    //             len2 = cur_len;
    //             vec2 = points[i];
    //         }
    //     }
    // }
    // ld ln = len(vec1, vec2);
    // ld ln1 = abs(len1);
    // ld ln2 = abs(len2);
    // ld ost = abs(ln1 - ln2);
    cout << ans << endl;
}


int main() {
    cout << fixed << setprecision(12);
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
    cin >> tt;
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
