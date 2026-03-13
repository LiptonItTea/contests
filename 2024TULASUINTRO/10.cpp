#include <iostream>
#include <list>

using namespace std;

struct Entry {
    int x;
    int y;
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int m, n;
    cin >> m >> n;

    string* data = new string[m];
    for (int i = 0; i < m; i++){
        cin >> data[i];
    }


    for (int y = 0; y < m; y++){
        if(data[y][0] = 'X')
            continue;
    }
}