#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        long long h;
        cin >> n >> h;

        int* array = new int[n];
        for (int i = 0; i < n; i++){
            cin >> array[i];
        }

        //binary search, find first good
        long long minK = 0;
        long long maxK = h + 100;
        unordered_map<int, bool> solved;


        long long k = (maxK + minK) / 2;
        while(true){
            //calculate damage (DAMAGE=1 !!!)
            long long damage = 0;
            for (int i = 1; i < n; i++){
                long long timeDelta = array[i] - array[i - 1];
                long long timeDamage = min(timeDelta, k);
                damage += timeDamage;
            }
            //last hit
            damage += k;

            if(damage >= h){
                solved[k] = true;
            }
            else{
                solved[k] = false;
            }
            //exit
            if(solved.find(k - 1) != solved.end() && solved.find(k) != solved.end() && solved[k - 1] == false && solved[k] == true){
                break;
            }
            if(solved.find(k) != solved.end() && solved.find(k + 1) != solved.end() && solved[k] == false && solved[k + 1] == true){
                k += 1;
                break;
            }

            if(solved[k] == true){
                maxK = k;
            }
            else{
                minK = k;
            }

            k = (maxK + minK) / 2;
        }
        cout << "" << k << "\n";
    }
}