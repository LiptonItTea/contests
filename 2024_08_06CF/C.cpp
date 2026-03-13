#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, s, m;
        cin >> n >> s >> m;

        int prevRight = 0;
        bool found = false;
        for (int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;

            if(l - prevRight >= s){
                found = true;
            }

            prevRight = r;
        }
        if(m - prevRight >= s){
            found = true;
        }

        if(found)
            cout << "YES\n";
        else
            cout << "NO\n"; 
    }
}