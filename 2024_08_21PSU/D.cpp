#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    map<int, int> levels;
    for (int i = 0; i < n; i++){
        int a, h;
        cin >> a >> h;

        int upLevel = max(0, a) + h;
        levels[upLevel]++;
    }
    int lowestLevel = levels.begin()->first;
    int amount = levels.begin()->second;

    string operations;
    cin >> operations;

    int lost = 0;
    int currLevel = 0;
    for (int i = 0; i < m; i++){
        // cout << currLevel << " " << lost << "\n";
        char op = operations[i];
        if(op == '+')
            currLevel++;
        else
            currLevel--;

        if(currLevel == lowestLevel){
            lost += amount;
            currLevel -= amount;
        }
    }

    cout << lost;
}