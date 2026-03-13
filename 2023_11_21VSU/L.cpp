#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int parseTime(unordered_map<string, int>& days){
    string temp;
    cin >> temp;
    int time = days[temp] * 24 * 60;
    //hour
    cin >> temp;
    time += stoi(temp.substr(0, 3)) * 60;
    time += stoi(temp.substr(4, 6));

    return time;
}

const int weekTime = 7 * 24 * 60;

int main(){
    unordered_map<string, int> days;
    days["monday"] = 1;
    days["tuesday"] = 2;
    days["wednesday"] = 3;
    days["thursday"] = 4;
    days["friday"] = 5;
    days["saturday"] = 6;
    days["sunday"] = 7;

    int confStartTime = parseTime(days);
    int confEndTime = parseTime(days);

    int n, m;
    cin >> n >> m;

    int minInTime = INT_MAX;
    for (int i = 0; i < n; i++){
        int departure = parseTime(days);
        int arrival = parseTime(days);

        //arrival before confStartTime
        int waitTime = confStartTime - arrival;
        if(waitTime < 0)
            waitTime += weekTime;
        
        if(arrival < departure){
            arrival += weekTime;
        }
        waitTime += arrival - departure;
        minInTime = min(minInTime, waitTime);
    }
    int minOutTime = INT_MAX;
    for (int i = 0; i < m; i++){
        int departure = parseTime(days);
        int arrival = parseTime(days);

        //departure after confEndTime
        int waitTime = departure - confEndTime;
        if(waitTime < 0)
            waitTime += weekTime;
        
        if(arrival < departure)
            arrival += weekTime;
        
        waitTime += arrival - departure;
        minOutTime = min(minOutTime, waitTime);
    }

    if(confEndTime < confStartTime){
        confEndTime += weekTime;
    }

    cout << minInTime + minOutTime + confEndTime - confStartTime;
}