#include <map>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string iToB(int num, int digits){
    string result;
    while(num != 0){
        result += (char) (48 + num % 2);
        num /= 2;
    }
    int curlen = result.length();
    for (int i = 0; i < digits - curlen; i++){
        result += "0";
    }

    string inversed;
    for (int i = 0; i < result.length(); i++){
        inversed += result[result.length() - 1 - i];
    }
    return inversed;
}

int main(){
    //phase 1 - initialize dict
    map<string, string> dict;
    map<string, string> invDict;
    string curr = "A";
    int counter = 0;
    for (int i = 0; i < 26; i++){
        dict[iToB(counter, 5)] = curr;
        curr[0]++;
        counter++;
    }
    dict[iToB(counter, 5)] = "_";

    //phase 2 - decode string
    map<char, string> hexes;
    counter = 0;
    hexes['0'] = iToB(counter++, 4);
    hexes['1'] = iToB(counter++, 4);
    hexes['2'] = iToB(counter++, 4);
    hexes['3'] = iToB(counter++, 4);
    hexes['4'] = iToB(counter++, 4);
    hexes['5'] = iToB(counter++, 4);
    hexes['6'] = iToB(counter++, 4);
    hexes['7'] = iToB(counter++, 4);
    hexes['8'] = iToB(counter++, 4);
    hexes['9'] = iToB(counter++, 4);
    hexes['A'] = iToB(counter++, 4);
    hexes['B'] = iToB(counter++, 4);
    hexes['C'] = iToB(counter++, 4);
    hexes['D'] = iToB(counter++, 4);
    hexes['E'] = iToB(counter++, 4);
    hexes['F'] = iToB(counter++, 4);

    string data;
    cin >> data;

    string bdata;
    for (int i = 0; i < data.length(); i++){
        bdata += hexes[data[i]];
    }

    //phase 3 - unarchive
    int curDigit = 5;
    int curIndex = 0;
    string unarchived;
    string currNewEntry;

    counter = 27;

    //dict[BINARY] = STRING
    while(curIndex + curDigit <= bdata.length()){
        string currBinSubStr = bdata.substr(curIndex, curDigit);
        string currSubstr = dict[currBinSubStr];
        if(currSubstr == ""){
            
        }

        curIndex += curDigit;

        unarchived += currSubstr;
        if(curIndex == curDigit){
            currNewEntry = currSubstr;
            continue;
        }
        //                                if digits(num) > digits, then don't care!!
        if(currNewEntry != "")
            dict[iToB(counter++, curDigit)] = currNewEntry + currSubstr[0];
        currNewEntry = currSubstr;
        int size = iToB(counter, curDigit).length();
        if(curDigit < size){
            curDigit = size;
            //remap
            string* tobechanged = new string[dict.size()];
            auto it = dict.begin();
            for (int i = 0; i < dict.size(); i++){
                tobechanged[i] = it->first;
                it++;
            }
            for (int i = 0; i < dict.size(); i++){
                string value = dict[tobechanged[i]];
                dict.erase(tobechanged[i]);
                dict["0" + tobechanged[i]] = value;
            }
        }
    }
    //addition - replace "_" symbol with SPACE
    for (int i = 0; i < unarchived.length(); i++){
        if(unarchived[i] == '_')
            unarchived[i] = ' ';
    }
    cout << unarchived;
}