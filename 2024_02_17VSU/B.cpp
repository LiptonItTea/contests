#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    list<string> result;
    do {
        result.push_back(s);
    }
    while(next_permutation(s.begin(), s.end()));

    cout << result.size() << "\n";
    for (auto it = result.begin(); it != result.end(); it++){
        cout << *it << "\n";
    }
}