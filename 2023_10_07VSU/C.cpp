#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        unordered_map<string, int> pool;
        string** array = new string*[3];
        for (int i = 0; i < 3; i++){
            array[i] = new string[n];
            for (int j = 0; j < n; j++){
                cin >> array[i][j];
                
                //unique
                if(pool.find(array[i][j]) == pool.end()){
                    pool[array[i][j]] = 3;
                }
                else{
                    pool[array[i][j]] -= 2;
                }
            }
        }

        for (int i = 0; i < 3; i++){
            int sum = 0;
            for (int j = 0; j < n; j++){
                sum += max(0, pool[array[i][j]]);
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
}