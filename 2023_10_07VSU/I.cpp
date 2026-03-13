#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        int uni = n / 3;
        int off1 = 0;
        int off2 = 0;
        if(n % 3 == 1)
            off1 = 1;
        else if(n % 3 == 2)
            off2 = 1;
        
        cout << uni + off1 << " " << uni + off2 << "\n";
    }
}