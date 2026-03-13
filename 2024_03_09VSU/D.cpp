#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_set<int> set;
    for (int i = 0; i < n; i++){
        set.insert(i + 1);
    }
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        if(v == i + 1){
            cout << "NO";
            return 0;
        }

        set.erase(v);
    }

    if(n == 2){
        cout << "YES";
        return 0;
    }
    
    if(set.size() > 0)
        cout << "YES";
    else
        cout << "NO";
}