#include <iostream>

using namespace std;

int main() {
    int ua, ub;
    cin >> ua >> ub;

    int a = max(ua, ub);
    int b = min(ua, ub);

    int sub = a - b;
    if(sub == 0){
        cout << a;
        return 0;
    }

    int counter = 0;
    for (int i = 1; i * i <= sub; i++){
        if(i > b){
            break;
        }

        if(sub % i == 0){
            counter++;
            if(i * i != sub && sub / i <= b){
                counter++;
            }
        }
    }

    cout << counter;
}