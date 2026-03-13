// #include <iostream>
// #include <math.h>
// #include <map>
// #include <set>
// #include <iomanip>
// #include <vector>
// #include <climits>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <list>
// #include <stack>

// #define ll long long

// using namespace std;

// struct Entry {
//     int i;
//     char sport;
//     ll fa, fb;
// };

// bool comp(const Entry &e1, const Entry &e2) {
//     ll diff1 = e1.fa - e1.fb;
//     ll diff2 = e2.fa - e2.fb;
//     return diff1 > diff2;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cout << fixed << setprecision(9);

//     int t;
//     cin >> t;

//     for (int _ = 0; _ < t; _++) {
//         ll n, k, x, y;
//         cin >> n >> k >> x >> y;

//         vector<Entry> guys (n);
//         for (int i = 0; i < n; i++) {
//             char type; int force;
//             cin >> type >> force;

//             guys[i].i = i;
//             guys[i].sport = type;
//             guys[i].fa = guys[i].fb = force;
//             if (type == 'A')
//                 guys[i].fb -= x;
//             else
//                 guys[i].fa -= y;
//         }

//         sort(guys.begin(), guys.end(), comp);

//         vector<ll> pref (n, LLONG_MIN);
//         ll suma = 0;
//         priority_queue<ll, vector<ll>, greater<ll>> heapa;
//         for (int i = 0; i < n; i++) {
//             suma += guys[i].fa;
//             heapa.push(guys[i].fa);

//             if (heapa.size() > k) {
//                 suma -= heapa.top();
//                 heapa.pop();
//             }
//             if (heapa.size() == k) {
//                 pref[i] = suma;
//             }
//         }

//         vector<ll> suff (n + 1, LLONG_MIN);
//         ll sumb = 0;
//         priority_queue<ll, vector<ll>, greater<ll>> heapb;
//         for (int i = n - 1; i >= 0; i--) {
//             sumb += guys[i].fb;
//             heapb.push(guys[i].fb);

//             if (heapb.size() > k) {
//                 sumb -= heapb.top();
//                 heapb.pop();
//             }
//             if (heapb.size() == k) {
//                 suff[i] = sumb;
//             }
//         }

//         ll best = LLONG_MIN;
//         for (int i = k - 1; i < n - k; i++) {
//             if (pref[i] != LLONG_MIN && suff[i + 1] != LLONG_MIN)
//                 best = max(best, pref[i] + suff[i + 1]);
//         }

//         cout << best << "\n";
//     }
// }

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
    int i;
    char sport;
    ll fa, fb;
};
    
bool comp(const Entry &e1, const Entry &e2) {
    ll diff1 = e1.fa - e1.fb;
    ll diff2 = e2.fa - e2.fb;
    return diff1 > diff2;
}
    
int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout << fixed << setprecision(9);
    
    int t;
    cin >> t;
    
    for (int _ = 0; _ < t; _++) {
        ll n, k, x, y;
        cin >> n >> k >> x >> y;
    
        vector<Entry> guys (n);
        for (int i = 0; i < n; i++) {
            char type; int force;
            cin >> type >> force;
    
            guys[i].i = i;
            guys[i].sport = type;
            guys[i].fa = guys[i].fb = force;
            if (type == 'A')
                guys[i].fb -= x;
            else
                guys[i].fa -= y;
        }
    
        sort(guys.begin(), guys.end(), comp);
    
        vector<ll> pref (n + 1, LLONG_MIN);
        ll suma = 0;
        priority_queue<int, vector<int>, greater<int>> heapa;
        for (int i = 0; i < n; i++) {
            suma += guys[i].fa;
            heapa.push(guys[i].fa);
    
            if (heapa.size() > k) {
                suma -= heapa.top();
                heapa.pop();
            }
            if (heapa.size() == k) {
                pref[i + 1] = suma;
            }
        }
    
        vector<ll> suff (n + 1, LLONG_MIN);
        ll sumb = 0;
        priority_queue<int, vector<int>, greater<int>> heapb;
        for (int i = n - 1; i >= 0; i--) {
            sumb += guys[i].fb;
            heapb.push(guys[i].fb);
    
            if (heapb.size() > k) {
                sumb -= heapb.top();
                heapb.pop();
            }
            if (heapb.size() == k) {
                suff[i] = sumb;
            }
        }
    
        ll best = LLONG_MIN;
        for (int i = k - 1; i <= n + 1 - k; i++) {
            if (pref[i] != LLONG_MIN && suff[i] != LLONG_MIN)
                best = max(best, pref[i] + suff[i]);
        }
    
        cout << best << "\n";
    }
}