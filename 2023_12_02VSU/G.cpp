#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;

    //shift - 2
    int* isPrime = new int[b];
    for (int i = 0; i < b; i++){
        isPrime[i] = 1;
    }
    isPrime[0] = 0;
    for (int i = 1; i <= b; i++){
        if(isPrime[i - 1] == 1){
            int num = i;
            for (int j = 2 * num; j <= b; j += num){
                isPrime[j - 1] = 0;
            }
        }
    }

    //prefix sums of [a, b]
    int* prefix = new int[b - a + 1];
    int curSum = 0;
    for (int i = a; i <= b; i++){
        curSum += isPrime[i - 1];
        prefix[i - a] = curSum;
    }

    // for (int i = a; i <= b; i++){
    //     cout << isPrime[i - 1] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < b - a + 1; i++){
    //     cout << prefix[i] << " ";
    // }
    // cout << "\n";

    int l = 0;
    int r = b - a + 1;
    int m = (r + l) / 2;
    unordered_map<int, bool> map;
    while(true){
        bool good = false;
        for (int i = m; i < b - a + 1; i++){
            int primes = prefix[i] - prefix[i - m] + isPrime[a - 1 + i - m];
            if(primes < k){
                good = false;
                break;
            }
            else{
                good = true;
            }
        }

        map[m] = good;

        if(m == 0 && good){
            cout << 1;
            return 0;
        }
        if(m == b - a && !good){
            cout << -1;
            return 0;
        }
        if(map.find(m - 1) != map.end() && map[m - 1] == false && map[m] == true){
            break;
        }
        if(map.find(m + 1) != map.end() && map[m] == false && map[m + 1] == true){
            m++;
            break;
        }
        
        if(good)
            r = m;
        else
            l = m;
        m = (r + l) / 2;
    }

    cout << m + 1;
}