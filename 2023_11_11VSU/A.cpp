#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void show(int* arr, int arr_size){
    for (int i = 0; i < arr_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T> bool greaterComp(T x1, T x2){
    return x1 > x2;
}

template <class T> bool absComp(T x1, T x2){
    return abs(x1) > abs(x2);
}

int main(){
    int t;
    cin >> t;
    int*** result = new int**[t];
    int* lens = new int[t];
    bool debug = false;
    
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        lens[i] = n;
        int * data = new int[n];
        for (int j = 0; j < n; j++){
            cin >> data[j];
        }
        result[i] = new int*[2];
        result[i][0] = new int[n];
        result[i][1] = new int[n];
        sort(data, data + n, greaterComp<int>);
        if(debug){
            cout << "ascending: " << endl;
            show(data, n);
        }
        int counter = 0;
        for (int j = 0; j < n; j++){
            if(data[j] > 0)
                counter++;
            else
                counter--;
            result[i][0][j] = counter;
        }
        sort(data, data + n, absComp<int>);
        if(debug){
            cout << "after absolute sortion: " << endl;
            show(data, n);
        }
        int next_pair_index = 0;
        for (int j = 0; j < n - 1; j++){
            if(debug)
                cout << "Checking pair: " << data[j] << " " << data[j + 1] << " = " << (data[j] + data[j + 1] == 0) << endl;
            if(data[j] + data[j + 1] == 0){
                int a = data[next_pair_index];
                int b = data[next_pair_index + 1];
                data[next_pair_index] = max(data[j], data[j + 1]);
                data[next_pair_index + 1] = min(data[j + 1], data[j]);
                if(j != next_pair_index + 1){
                    data[j] = a;
                    data[j + 1] = b;
                }
                else{
                    data[j + 1] = a;
                }
                next_pair_index += 2;
            }
        }
        if(debug){
            cout << "modifiied: " << endl;
            show(data, n);
        }
        counter = 0;
        for (int j = 0; j < n; j++){
            if(data[j] > 0)
                counter++;
            else
                counter--;
            result[i][1][j] = counter;
        }
        delete[] data;
    }

    for (int i = 0; i < t; i++){
        for (int j = 0; j < 2; j++){
            show(result[i][j], lens[i]);
        }
    }
}