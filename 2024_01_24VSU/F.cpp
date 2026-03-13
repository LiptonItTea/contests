#include <iostream>

using namespace std;

int indexOf(int* array, int size, int element){
    for (int i = 0; i < size; i++){
        if(array[i] == element)
            return i;
    }
    return -1;
}

void printArray(int* array, int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << ", ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    int* p = new int[n];
    int* d = new int[n];

    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }

    for (int i = 0; i < n; i++){
        int counter = 0;
        int* newp = new int[n];
        for (int j = 0; j < n; j++){
            newp[j] = p[j];
        }
        for (int j = 0; j < i + 1; j++){
            // d[j] - deleted element
            bool bad = true;
            newp[indexOf(newp, n, d[j])] = 0;
            int checkingElement = d[j];
            printArray(newp, n);
            while(bad){
                if(newp[checkingElement - 1] != checkingElement){
                    int swch = newp[checkingElement - 1];
                    newp[checkingElement - 1] = checkingElement;
                    checkingElement = swch;
                    counter++;
                }
                else{
                    bad = false;
                    break;
                }
            }
        }
        delete newp;
        cout << counter << endl;
    }
}