#include <iostream>
#include <string>

using namespace std;

int* z_func_lazy(string& s, int n){
    int* z = new int[n];
    fill(z, z + n, 0);
    for (int i = 1; i < n; i++){
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]){
            z[i]++;
        }
    }

    return z;
}

int* z_func(string& s, int n){
    int* z = new int[n];
    fill(z, z + n, 0);

    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++){
        if(i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        }

        while(i + z[i] < n && s[i + z[i]] == s[z[i]]){
            z[i]++;
        }

        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main () {
    int n;
    cin >> n;

    string s;
    cin >> s;
    
    int* z_lazy = z_func_lazy(s, n);
    for (int i = 0; i < n; i++){
        cout << z_lazy[i] << " ";
    }
    cout << "\n";

    int* z_good = z_func(s, n);
    for (int i = 0; i < n; i++){
        cout << z_good[i] << " ";
    }
}