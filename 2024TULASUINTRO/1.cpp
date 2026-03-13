#include <iostream>

using namespace std;

int main(){
    int v1, v2, t1, t2;
    cin >> v1 >> v2 >> t1 >> t2;
    int s = v1 * t1;
    s += (v1 - v2) * t2;
    cout << s;
}