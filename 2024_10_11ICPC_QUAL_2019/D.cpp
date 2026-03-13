#include <iostream>
#include <set>

using namespace std;

bool getCyphers(set<int>& cy, int minutes){
    int hour = minutes / 60;
    int minu = minutes % 60;

    for (int i = 0; i < 2; i++){
        if(cy.find(hour % 10) != cy.end())
            return false;
        cy.insert(hour % 10);
        hour /= 10;
    }
    for (int i = 0; i < 2; i++){
        if(cy.find(minu % 10) != cy.end())
            return false;
        cy.insert(minu % 10);
        minu /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    for (int minutes = 0; minutes <= 1440; minutes++){
        int shiftMinutes = (minutes + k) % 1440;
        
        set<int> cyphers;
        bool exists = getCyphers(cyphers, minutes);
        if(!exists)
            continue;
        
        set<int> shiftCyphers;
        exists = getCyphers(shiftCyphers, shiftMinutes);
        if(!exists)
            continue;

        bool good = true;
        for (auto it = cyphers.begin(); it != cyphers.end(); it++){
            if(shiftCyphers.find(*it) != shiftCyphers.end()){
                good = false;
                break;
            }
        }

        if(good){
            if(minutes / 60 < 10)
                cout << 0;
            cout << minutes / 60 << ":";
            if(minutes % 60 < 10)
                cout << 0;
            cout << minutes % 60;
            return 0;
        }
        
    }

    cout << "PASS";
}