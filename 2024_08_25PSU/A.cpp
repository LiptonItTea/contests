#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    string* result = new string[2];
    
    int additions = (n - 4) / 2;
    int type = n % 2;

    if(type % 2 == 0){
        result[0] += " ";
        result[1] += "#";
        for (int i = 0; i < additions; i++){
            result[0] += "# ";
            result[1] += "##";
        }
    }
    else{
        for (int i = 0; i < additions + 1; i++){
            result[0] += " #";
            result[1] += "##";
        }
    }
    cout << result[0] << "\n" << result[1];
}