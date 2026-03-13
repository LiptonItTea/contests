#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

double e = 0.000001;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    long long T;
    cin >> T;

    for (long long _ = 0; _ < T; _++){
        long long h, c, t;
        cin >> h >> c >> t;

        double mid = (h + c) / 2.0;
        if(t <= mid){
            cout << 2 << "\n";
            continue;
        }
        if(t == h){
            cout << 1 << "\n";
            continue;
        }

        // int k = (h - t) / (2 * t - h - c);
        // double temp1 = ((k + 1) * h + k * c) / (2 * k + 1.0);
        // double temp2 = ((k + 2) * h + (k + 1) * c) / (2 * (k + 1) + 1.0);
        // if(temp1 - t < t - temp2){
        //     if(temp1 - t < h - t){
        //         cout << 2 * k + 1 << "\n";
        //     }
        //     else{
        //         cout << 1 << "\n";
        //     }
        // }
        // else{
        //     cout << 2 * (k + 1) + 1 << "\n";
        // }

        long long l = -2;
        long long r = INT_MAX / 100;
        long long m = (r + l) / 2;
        m += m % 2;
        unordered_map<long long, double> map;
        while(true){
            double delta = ((h + c) * (m / 2) + h - t * (m + 1)) / (m + 1.0);

            if(delta == 0){
                break;
            }
            map[m] = delta;
            
            if(map.find(m - 2) != map.end() && map[m] < 0 && 0 < map[m - 2]){
                if(-map[m] < map[m - 2]){
                    break;
                }
                else{
                    // cout << setprecision(23) << -map[m] << " " << map[m - 2];
                    m -= 2;
                    break;
                }
            }
            if(map.find(m + 2) != map.end() && map[m + 2] < 0 && 0 < map[m]){
                if(-map[m + 2] < map[m]){
                    m += 2;
                    break;
                }
                else{
                    break;
                }
            }

            if(delta < 0){
                r = m;
            }
            else{
                l = m;
            }
            m = (r + l) / 2;
            m += m % 2;
        }
        cout << m + 1 << '\n';
    }
}