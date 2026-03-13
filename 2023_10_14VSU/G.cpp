#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    //find humans who can be saved, others should be subtracted
    long long n, m, k, t;
    cin >> n >> m >> k >> t;

    long long* humans = new long long[n];
    for (long long i = 0; i < n; i++){
        cin >> humans[i];
    }

    long long* shelters = new long long[m];
    long long* carry = new long long[m];
    for (long long i = 0; i < m; i++){
        cin >> shelters[i];
        carry[i] = k;
    }

    sort(humans, humans + n);
    sort(shelters, shelters + m);

    // for (int i = 0; i < n; i++){
    //     cout << humans[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < m; i++){
    //     cout << shelters[i] << " ";
    // }
    // cout << "\n";

    long long curShelter = 0;
    long long saved = n;
    for (int i = 0; i < n; i++){
        if(carry[curShelter] > 0 && abs(humans[i] - shelters[curShelter]) <= t){
            carry[curShelter]--;
        }
        else{
            bool found = false;
            for (int j = curShelter + 1; j < m; j++){
                if(carry[j] > 0 && abs(humans[i] - shelters[j]) <= t){
                    curShelter = j;
                    carry[curShelter]--;
                    found = true;
                    break;
                }
            }
            if(found)
                continue;
            saved--;
        }
    }
    cout << saved;
}