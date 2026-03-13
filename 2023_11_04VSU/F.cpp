#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* a = new int[n];
    unordered_map<int, int> aNums;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        aNums[a[i]]++;
    }

    int* b = new int[n];
    int first = -1,
        second = -1;
    for (int i = 0; i < n; i++){
        cin >> b[i];
        if(a[i] != b[i]){
            if(first == -1)
                first = i;
            else
                second = i;
        }
    }

    if(second != -1){
        if(aNums[a[first]] == 2 && aNums.find(b[first]) == aNums.end())
            a[first] = b[first];
        else{
            a[second] = b[second];
        }
    }
    else{
        for (int i = 1; i < n + 1; i++){
            if(aNums.find(i) == aNums.end()){
                a[first] = i;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}