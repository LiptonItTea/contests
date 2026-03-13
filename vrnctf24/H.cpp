#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;
    
    long long result = 0;
    for (int i = 0; i < n.length(); i++){
        long cypher = n[i] - 48;
        // ??? why not min(cypher, 4)
        if(cypher > 4){
            result += pow(5, n.length() - i) - 1;
            break;
        }
        result += cypher * pow(5, n.length() - i - 1);
    }
    cout << result;
}