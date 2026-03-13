#include <iostream>
#include <set>

const long long ten9 = 1000000000ll;
using namespace std;

int main() {
    //init tree of squares
    // set<long long> squares;
    // long long i = 0;
    // while (i * i > 0ll && i * i <= LLONG_MAX){
    //     squares.insert(i * i);
    //     i++;
    // }

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        long long n, i;
        cin >> n >> i;

        if(n == 1){
            cout << "1 0\n";
            continue;
        }

        long long k = 0;
        int currSolution = 0;
        bool found = false;
        while(true){
            long long x = k * n + 1ll;
            long long toCheck = k * (k * n + 2ll);

            long long y = sqrt(toCheck);

            if(x > ten9 && y > ten9)
                break;
            // cout << x << " " << y << "\n";
            if(y * y == toCheck){
                currSolution++;
            }

            if(currSolution == i){
                cout << x << " " << y << "\n";
                found = true;
                break;
            }

            k++;
        }
        
        if(!found)
            cout << -1;
    }

    // for (int _ = 0; _ < t; _++){
    //     long long n, i;
    //     cin >> n >> i;

    //     long long currSolution = 0;
    //     bool found = false;
    //     for (auto it = squares.begin(); it != squares.end(); it++){
    //         long long x2 = *it;
            
    //         if((x2 - 1) % n == 0ll){
    //             long long y2 = (x2 - 1ll) / n;
                
    //             if(squares.find(y2) != squares.end()){
    //                 currSolution++;
    //             }

    //             if(currSolution == i){
    //                 cout << sqrt(x2) << " " << sqrt(y2) << "\n";
    //                 found = true;
    //                 break;
    //             }
    //         }
    //     }

    //     if(!found)
    //         cout << "NO\n";
    // }
}