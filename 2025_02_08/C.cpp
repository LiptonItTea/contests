#include <iostream>
#include <map>
#include <bit>

using namespace std;

int near2(int n) {
    int c = 1;
    while (c <= n)
        c <<= 1;
    
    return c;
}

map<int, int> precooked {
    {3, 1},
    {7, 1},
    {15, 5},
    {31, 1},
    {63, 21},        
    {127, 1},       
    {255, 85},    
    {511, 73},   
    {1023, 341},  
    {2047, 89},   
    {4095, 1365}, 
    {8191, 1}   , 
    {16383, 5461},
    {32767, 4681},
    {65535, 21845},
    {131071, 1},
    {262143, 87381},
    {524287, 1},
    {1048575, 349525},
    {2097151, 299593},
    {4194303, 1398101},
    {8388607, 178481},
    {16777215, 5592405},
    {33554431, 1082401},
};

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        unsigned int a;
        cin >> a;

        if (precooked.find(a) != precooked.end()){
            cout << precooked[a] << "\n";
            continue;
        }

        cout << (1 << (32 - countl_zero(a))) - 1 << "\n";
    }
}