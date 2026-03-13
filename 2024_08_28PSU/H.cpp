#include <iostream>
#include <algorithm>

using namespace std;

int k;
long long counter = 0;

int* mergeSort(int* array, int r){
    if(r == 1){
        return array;
    }

    int* firstHalf = new int[r / 2];
    for (int i = 0; i < r / 2; i++){
        firstHalf[i] = array[i];
    }
    firstHalf = mergeSort(firstHalf, r / 2);
    int* secondHalf = new int[r - r / 2];
    for (int i = 0; i < r - r / 2; i++){
        secondHalf[i] = array[i + r / 2];
    }
    secondHalf = mergeSort(secondHalf, r - r / 2);

    int a = 0;
    int b = 0;
    for (int i = 0; i < r; i++){
        if(a == r / 2){
            array[i] = secondHalf[b++];
        }
        else if(b == r - r / 2){
            array[i] = firstHalf[a++];
        }
        else if(firstHalf[a] < secondHalf[b]){
            array[i] = firstHalf[a];
            a++;
        }
        else{
            array[i] = secondHalf[b];
            if(firstHalf[a] - secondHalf[b] >= k){
                counter += (long long) r / 2 - a;
            }
            b++;
        }
    }

    return array;
}

int main(){
    cout << "start\n";
    freopen("k-inversions.in", "r", stdin);
    freopen("k-inversions.out", "w", stdout);

    int n;
    cin >> n >> k;

    int* array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    array = mergeSort(array, n);

    cout << counter;
}