#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string* data = new string[n];

    for (int i = 0; i < n; i++){
        cin >> data[i];
    }

    for (int y = 1; y < n - 1; y++){
        for (int x = 1; x < n - 1; x++){
            //mask
            if (data[y - 1].at(x) == '#' &&
                data[y].at(x - 1) == '#' &&
                data[y].at(x) == '#' &&
                data[y + 1].at(x) == '#' &&
                data[y].at(x + 1) == '#'){
                    data[y - 1][x] = 'o';
                    data[y][x - 1] = 'o';
                    data[y][x] = 'o';
                    data[y + 1][x] = 'o';
                    data[y][x + 1] = 'o';
                }
        }
    }

    bool good = true;
    for (int y = 0; y < n; y++){
        for (int x = 0; x < n; x++){
            if(data[y][x] == '#'){
                good = false;
                goto exit;
            }
        }
    }
    exit:
    if(good)
        cout << "YES";
    else
        cout << "NO";
}