#include <iostream>
#include <vector>
#include <set>

#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, x;
        cin >> n >> x;

        //greedy
        set<ll> divs;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;

            if (a == 1)
                continue;
            
            bool found = false;

            if (x % a == 0) {
                auto it = divs.begin();
                vector<ll> new_divs (divs.size(), 0);
                for (int j = 0; j < divs.size(); j++){
                    new_divs[j] = a * (*it);
                    if (new_divs[j] == x){
                        found = true;
                        break;
                    }
                    it++;
                }

                if (found) {
                    counter++;
                    divs.clear();
                    divs.insert(a);
                    continue;
                }

                for (int j = 0; j < new_divs.size(); j++)
                    if (new_divs[j] <= 100001)
                        divs.insert(new_divs[j]);
                divs.insert(a);
            }
        }

        cout << counter + 1 << "\n";
    }
}