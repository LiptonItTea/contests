#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long fastPow(long long num, long long pow){
    if(pow == 0ll)
        return 1;
    if(pow % 2 == 0ll){
        long long result = fastPow(num, pow / 2);
        return result * result;
    }
    return num * fastPow(num, pow - 1ll);
}

map<pair<long long, long long>, long long> dict;
long long f(long long n, long long c){
    if(dict.find({n, c}) != dict.end()){
        return dict[{n, c}];
    }

    if(c >= n){
        dict[{n, c}] = fastPow(3ll, n - 1ll);
        return fastPow(3ll, n - 1ll);
    }
    if(n == 1ll && c > 0ll){
        dict[{n, c}] = 1ll;
        return 1ll;
    }
    if(c <= 0ll){
        dict[{n, c}] = 0ll;
        return 0ll;
    }
    long long result = f(n - 1ll, c - 1ll) + f(n - 1ll, c) + f(n - 1ll, c + 1ll);
    dict[{n, c}] = result;
    return result;
}

void solve(long long n, long long x){
    long long c = 1;
    while(x >= f(n, c)){
        if(c >= n){
            c += x / fastPow(3, n - 1ll);
            x = x % fastPow(3, n - 1ll);
            break;
        }
        x -= f(n, c);
        c++;
    }
    cout << c << " ";

    long long currN = n;
    for (int i = 0; i < n - 1; i++){
        for (int d = -1ll; d <= 1; d++){
            if(x < f(currN - 1ll, c + d)){
                cout << c + d << " ";
                c += d;
                currN--;
                break;
            }
            x -= f(currN - 1ll, c + d);
        }
    }
}

int main() {
    // vector<int> pref (40, 0);
    // int i = 0;
    // int counter = 0;
    // vector<int> curr (40, 1);
    // while(i < 40) {
    //     while(curr[i + 1] == 1){
    //         if(curr[0] - curr[1] < 1){
    //             curr[0]++;
    //             counter++;
    //         }
    //         else{
    //             for (int k = 1; k < 40 - 1; k++){
    //                 if(curr[k] - curr[k + 1] < 1){
    //                     curr[k]++;
    //                     counter++;
    //                     for (int l = k - 1; l >= 0; l--)
    //                         curr[l] = max(curr[l + 1] - 1, 1);
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     cout << "Set i " << counter << "\n";
    //     pref[i] = i;
    //     i++;
    // }

    // for (int j = 0; j < 40; j++){
    //     cout << pref[j] << " ";
    // }

    long long n, x;
    cin >> n >> x;

    solve(n, x);
    // for (int i = 1; i <= 40; i++){
    //     solve(i, 1000000000000000000);
    //     cout << "\n";
    // }
}