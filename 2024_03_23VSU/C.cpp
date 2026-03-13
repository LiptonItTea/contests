#include <iostream>
#include <map>

using namespace std;

long long modu = 1000000007;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        int* a = new int[n];
        //  a         b    validity
        map<int, pair<int, bool>> links;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        int* b = new int[n];
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }

        int* d = new int[n];
        for (int i = 0; i < n; i++){
            cin >> d[i];
            links[a[i]] = {b[i], d[i] == 0};
        }

        long long result = 1;
        for (auto it = links.begin(); it != links.end(); it++){
            int currA = it->first;
            int currB = it->second.first;
            bool good = it->second.second && (currA != currB);
            if(!good)
                continue;

            int curr = currB;
            while(curr != currA){
                auto it = links.find(curr);
                if(it->second.second == false){
                    good = false;
                }
                it->second.second = false;
                curr = it->second.first;
            }
            if(good)
                result = (result * 2ll) % modu;
        }
        // for (int i = 0; i < n; i++){
        //     if(c[i] == 1)
        //         continue;
            
        //     int curr = b[i];
        //     bool good = (a[i] != b[i]) && (d[i] == 0);
        //     while(curr != a[i]){
        //         for (int j = 0; j < n; j++){
        //             if(curr == a[j]){
        //                 curr = b[j];
        //                 c[j] = 1;

        //                 if(d[j] != 0)
        //                     good = false;
        //                 break;
        //             }
        //         }
        //     }
        //     if(good)
        //         result = (result * 2ll) % modu;
        // }

        cout << result << "\n";
    }
}