#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<string, string> roles;
    string sickName;
    int mafiaAmount = 0;
    for (int i = 0; i < n; i++){
        string name, role;
        cin >> name >> role;

        roles[name] = role;

        if(role == "sick"){
            sickName = name;
        }
        if(role == "mafia"){
            mafiaAmount++;
        }
    }

    int m;
    cin >> m;

    int isMafiaKilling = 0;
    int isManiacKilling = 0;
    int isDoctorHealing = 0;
    string mafiaTarget;
    string maniacTarget;
    string doctorTaget;
    string sickTarget;

    for (int i = 0; i < m; i++){
        string role, target;
        cin >> role >> target;

        if(role == "mafia"){
            isMafiaKilling = mafiaAmount;
            mafiaTarget = target;
        }
        if(role == "maniac"){
            isManiacKilling = 1;
            maniacTarget = target;
        }
        if(role == "doctor"){
            isDoctorHealing = 1;
            doctorTaget = target;
        }
        if(role == "sick"){
            sickTarget = target;
        }
    }

    if(mafiaTarget != "" && sickTarget != "" && (sickTarget == mafiaTarget || sickTarget == maniacTarget)){
        if(doctorTaget != sickName)
            roles.erase(sickName);
    }
    if(sickTarget != "" && roles[sickTarget] == "maniac"){
        isManiacKilling = 0;
    }
    if(sickTarget != "" && roles[sickTarget] == "mafia"){
        isMafiaKilling--;
    }
    if(sickTarget != "" && roles[sickTarget] == "doctor"){
        isDoctorHealing = 0;
    }

    if(isDoctorHealing){
        if(doctorTaget == mafiaTarget){
            isMafiaKilling = 0;
        }
        if(doctorTaget == maniacTarget){
            isManiacKilling = 0;
        }
    }

    if(isManiacKilling){
        roles.erase(maniacTarget);
    }
    if(isMafiaKilling){
        roles.erase(mafiaTarget);
    }

    cout << roles.size() << "\n";
    for (auto it = roles.begin(); it != roles.end(); it++){
        cout << it->first << " " << it->second << "\n";
    }
}