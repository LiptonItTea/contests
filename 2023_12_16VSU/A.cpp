#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int maxLen = max(a, max(b, c));
    int otherLen = a + b + c - maxLen;

    cout << max(0, maxLen - otherLen + 1);
}