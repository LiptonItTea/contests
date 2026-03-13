#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> pref (n);
    for (int i = 0; i < n; i++)
        cin >> pref[i];
    
    cout << pref[0] << " ";
    for (int i = 1; i < n; i++){
        cout << pref[i] - pref[i - 1] << " ";
    }
}