#include <iostream>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        long long c;
        cin >> c;

        if(c < 6){
            cout << "0\n";  
            continue;
        }

        map<long long, long long> dict;
        long long l = 1;
        long long r = 1e10 + 100;
        long long n;

        while(true){
            n = (l + r) / 2ll;

            long long k = (1ll + n) * n / 2ll;
            dict[n] = k;

            if(dict.find(n - 1) != dict.end() && dict[n - 1] <= c && c < dict[n]){
                n--;
                break;
            }
            if(dict.find(n + 1) != dict.end() && dict[n] <= c && c < dict[n + 1]){
                break;
            }
            if(k == c)
                break;

            if(k > c){
                r = n;
            }
            else{
                l = n;
            }
        }

        cout << (1ll + n) * n / 2ll << "\n";
    }
}