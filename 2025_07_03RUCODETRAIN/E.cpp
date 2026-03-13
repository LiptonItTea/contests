#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>
#include <bitset>

#define ll long long

using namespace std;

bitset<64> crc16ccit(bitset<32> data, bitset<32> div) {
    bitset<32> result {data};
    result <<= 8;

    for (int i = 16 - 9; i >= 0; i--) {
        if (result[i + 8]) {
            result = result ^ (div << i);
        }
    }
    return result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    // ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;

    cout << bitset<8> {87} << " " << bitset<8> {263} << "\n";
    
    cout << crc16ccit(bitset<16> {87}, bitset<16> {263});
}