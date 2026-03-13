#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparePairs(pair<long long, long long> p1, pair<long long, long long> p2){
    return p1.second < p2.second;
}

int main () {
    int n;
    cin >> n;

    vector<pair<long long, long long>> pairs;
    pairs.reserve(n);
    for (int i = 0; i < n; i++){
        pair<long long, long long> p;
        cin >> p.first >> p.second;

        pairs.push_back(p);
    }
    sort(pairs.begin(), pairs.end(), comparePairs);

    int l = 0;
    int r = n - 1;

    long long k = 0;
    long long cost = 0;
    while (l <= r){
        if(pairs[l].first == 0ll)
            break;
        
        int i = r;
        while (r >= l){
            long long amount = min(pairs[r].first, max(0ll, pairs[l].second - k));
            k += amount;
            cost += amount * 2ll;
            pairs[r].first -= amount;

            if(pairs[r].first == 0ll)
                r--;
            else
                break;
        }
        k += pairs[l].first;
        cost += pairs[l].first;
        pairs[l].first = 0;
        l++;
    }

    cout << cost;
}