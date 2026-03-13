#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long long rt, rj;
    cin >> rt >> rj;
    rt--; rj--;

    double tempst, tempsj;
    cin >> tempst >> tempsj;

    long long st = round(100.0 * tempst);
    long long sj = round(100.0 * tempsj);

    if (rt * sj < rj * st){
        cout << "TAOYUAN";
    }
    else if(rt * sj > rj * st){
        cout << "JAKARTA";
    }
    else{
        cout << "SAME";
    }
}