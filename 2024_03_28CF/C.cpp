#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    string* data = new string[t];
    for (int i = 0; i < t; i++){
        cin >> data[i];
    }

    for (int i = 0 ; i < t; i++){
        string time = data[i];
        int hour = ((int) time.at(0)) - 48;
        hour *= 10;
        hour += ((int) time.at(1)) - 48;
        
        int newHour = hour % 12;
        if (newHour == 0)
            newHour = 12;
        
        int minute = ((int) time.at(3)) - 48;
        minute *= 10;
        minute += ((int) time.at(4)) - 48;
        
        printf("%02d:%02d %s\n", newHour, minute, (hour >= 12 ? "PM" : "AM"));
    }
}