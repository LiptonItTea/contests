#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> dict {{'0', "0000"},
                                  {'1', "0001"},
                                  {'2', "0010"},
                                  {'3', "0011"},
                                  {'4', "0100"},
                                  {'5', "0101"},
                                  {'6', "0110"},
                                  {'7', "0111"},
                                  {'8', "1000"},
                                  {'9', "1001"},
                                  {'A', "1010"},
                                  {'B', "1011"},
                                  {'C', "1100"},
                                  {'D', "1101"},
                                  {'E', "1110"},
                                  {'F', "1111"}};

string hexToBin(string& hex){
    string bin;
    for (int i = 0; i < hex.length(); i++){
        bin += dict[hex[i]];
    }

    return bin;
}

int binToDec(string& bin){
    int result = 0;
    for (int i = 0; i < bin.length(); i++){
        int cipher = bin[i] - 48;
        result += cipher * (1 << (bin.length() - 1 - i));
    }

    return result;
}

int main(){
    string hex;
    cin >> hex;

    string bin = hexToBin(hex);

    int previ = 0;
    int i = 0;
    int k = 4;
    while(i < bin.length()){
        while(bin[i] == '1')
            i++;
        
        int pi = i - previ;
        i++;

        string bistring = bin.substr(i, k);
        int bi = binToDec(bistring);
        i += k;
        previ = i;

        int ai = pi * (1 << k) + bi;
        if(ai == 0)
            break;
        cout << ai << " ";

        if(pi == 0)
            k -= 2;
        else if(pi > 1){
            k += pi + 1;
        }
    }
}