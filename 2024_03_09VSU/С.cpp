#include <iostream>
#include <set>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;
        long long k;
        cin >> k;

        multiset<pair<long long, bool>> forces;
        for (int i = 0; i < n; i++){
            long long force;
            cin >> force;

            forces.insert({force, false});
        }

        long long bestResult = LLONG_MAX;

        for (int i = -1; i < n - 1; i++){
            if(i != -1){
                auto it = forces.begin();
                while(it->second && it != forces.end()){
                    it++;
                }
                long long force = it->first;
                forces.erase(it);
                forces.insert({force + k, true});
            }
            multiset<pair<long long, bool>> newForces = forces;
            for (int j = n; j > i; j--){
                if(j != n){
                    auto it = newForces.rbegin();
                    while(it->second && it != newForces.rend()){
                        it++;
                    }
                    long long force = it->first;
                    newForces.erase(next(it).base());
                    newForces.insert({force - k, true});
                }
                long long minForce = newForces.begin()->first;
                long long maxForce = newForces.rbegin()->first;

                bestResult = min(bestResult, maxForce - minForce);
            }
        }

        cout << bestResult << "\n";
    }
}