    #include <iostream>
    #include <algorithm>

    using namespace std;

    int main(){
        int n;
        cin >> n;

        int* array = new int[n];
        for (int i = 0; i < n; i++){
            cin >> array[i];
        }

        sort(array, array + n);
        // for (int i = 0; i < n; i++){
        //     cout << array[i] << " ";
        // }
        // cout << "\n";

        int cost = 0;
        for (int i = 1; i < n; i++){
            if(array[i - 1] == array[i]){
                cost += 1;
                array[i] += 1;
            }
            else if(array[i - 1] > array[i]){
                cost += array[i - 1] - array[i] + 1;
                array[i] += array[i - 1] - array[i] + 1;
            }
        }
        cout << cost;
    }