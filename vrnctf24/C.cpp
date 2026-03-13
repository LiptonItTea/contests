#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Entry {
    int lx, ly, rx, ry;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string* data = new string[n];

    for (int i = 0; i < n; i++){
        cin >> data[i];
    }

    vector<Entry> bounds;
    for (int y = 0; y < n; y++){
        for (int x = m - 1; x >= 0; x--){
            if(data[y][x] == 'x'){
                Entry e;
                e.rx = x;
                e.ry = y;

                for (int iy = y; iy < n; iy++){
                    if(data[iy][x] == '.'){
                        e.ly = iy - 1;
                        break;
                    }
                    if(iy == n - 1){
                        e.ly = n - 1;
                        break;
                    }
                }
                for (int ix = x; ix >= 0; ix--){
                    if(data[y][ix] == '.'){
                        e.lx = ix + 1;
                        break;
                    }
                    if(ix == 0){
                        e.lx = 0;
                        break;
                    }
                }

                for (int iy = y; iy <= e.ly; iy++){
                    for (int ix = x; ix >= e.lx; ix--){
                        data[iy][ix] = '0';
                    }
                }
                // cout << "entry: " << e.lx << " " << e.ly << " " << e.rx << " " << e.ry << "\n";
                // for (int i = 0; i < n; i++){
                //     cout << data[i] << "\n";
                // }
                bounds.push_back(e);
            }
        }
    }
    cout << bounds.size() << "\n";
    for (vector<Entry>::iterator it = bounds.begin(); it != bounds.end(); it++){
        Entry e = *it;
        cout << e.lx + 1 << " " << n - (e.ly) << " " << e.rx + 1 << " " << n - (e.ry) << "\n";
        // cout << e.lx << " " << e.ly << " " << e.rx << " " << e.ry << "\n";
    }
}