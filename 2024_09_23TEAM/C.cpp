#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a (n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<string> b (n);
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    int counter = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(a[i][j] != b[i][j])
                counter++;
        }
    }

    cout << counter;
}