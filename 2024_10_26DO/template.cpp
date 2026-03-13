#include <iostream>
#include <vector>


using namespace std;

int near2(int n){
    int i = 1;
    int c = 0;
    while (i < n){
        i *= 2;
        c++;
    }
    return c;
}

void build(vector<int>& array, vector<int>& b, int v, int l, int r){
    if(l == r){
        b[v] = array[l];
    }
    else{
        int c = (l + r) / 2;
        build(array, b, 2 * v, l, c);
        build(array, b, 2 * v + 1, c + 1, r);
        b[v] = b[v * 2] + b[v * 2 + 1];
    }
}

void changeValue(vector<int>& array, vector<int>& b, int i, int newValue, int v, int l, int r){
    if(l == r){
        array[i] = newValue;
        b[v] = newValue;
    }
    else{
        int c = (l + r) / 2;
        if(i <= c)
            changeValue(array, b, i, newValue, 2 * v, l, c);
        else
            changeValue(array, b, i, newValue, 2 * v + 1, c + 1, r);
        b[v] = b[v * 2] + b[v * 2 + 1];
    }
}

int getSum(vector<int>& array, vector<int>& b, int i, int j, int v, int l, int r){
    if (j < l || r < i){
        return 0;
    }
    
    if(i <= l && r <= j){
        return b[v];
    }

    int c = (l + r) / 2;
    return getSum(array, b, i, j, v * 2, l, c) + getSum(array, b, i, j, v * 2 + 1, c + 1, r);
}

int main () {
    vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int goodSize = 1 << near2(array.size());
    while(array.size() < goodSize){
        array.push_back(0);
    }

    vector<int> b (array.size() * 2, 0);
    build(array, b, 1, 0, array.size() - 1);

    // changeValue(array, b, 0, 0, 1, 0, array.size() - 1);

    for (int i = 0; i < array.size(); i++){
        cout << getSum(array, b, i, i + 1, 1, 0, array.size() - 1) << " ";
    }
}