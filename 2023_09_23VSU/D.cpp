#include <iostream>
#include <string>

using namespace std;

int main(){
    string n;
    cin >> n;

    if(n == "0"){
        cout << -1;
        return 0;
    }

    //calculate overall sum
    int sum = 0;
    for (int i = 0; i < n.length(); i++){
        sum += (int) n[i] - 48;
    }

    if(sum >= 81){
        cout << -1;
        return 0;
    }

    string m;
    while(sum > 0){
        int newSum = max(0, sum - 9);
        int ch = sum - newSum;

        sum = newSum;
        m += 48 + ch;
    }

    if(m == n){
        //add 0
        if(m.length() < 9){
            cout << m << "0";
            return 0;
        }
        //reverse
        for (int i = m.length() - 1; i >= 0; i--){
            cout << m[i];
        }
        return 0;
    }

    cout << m;
}