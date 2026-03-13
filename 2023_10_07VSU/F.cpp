#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        int even = 0;
        int uneven = 0;
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;

            if(num % 2 == 0){
                even++;
            }
            else{
                uneven++;
            }
        }

        cout << min(even, uneven) << "\n";
    }
}