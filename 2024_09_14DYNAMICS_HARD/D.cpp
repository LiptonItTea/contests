#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<pair<int, pair<int, int>>, bool> dict;
pair<int, pair<int, int>> reorder(pair<int, pair<int, int>> in){
    pair<int, pair<int, int>> p;
    int a = in.first;
    int b = in.second.first;
    int c =in.second.second;

    p.first = max(a, max(b, c));
    p.second.second = min(a, min(b, c));
    p.second.first = a + b + c - p.first - p.second.second;

    return p;
}
bool calculated(pair<int, pair<int, int>> in){
    pair<int, pair<int, int>> rein = reorder(in);
    if(dict.find(rein) != dict.end())
        return true;
    return false;
}
bool get(pair<int, pair<int, int>> in){
    pair<int, pair<int, int>> rein = reorder(in);
    return dict.find(rein)->second;
}

bool r(vector<int>& state, vector<int>& actions){
    pair<int, pair<int, int>> temp = reorder({state[0], {state[1], state[2]}});
    cout << "Called: " << temp.first << " " << temp.second.first << " " << temp.second.second << "\n";
    if(calculated({state[0], {state[1], state[2]}})){
        return get({state[0], {state[1], state[2]}});
    }

    if(state[0] == 0 && state[1] == 0 && state[2] == 0)
        return false;
    
    for (int action : actions){
        for (int i = 0; i < 3; i++){
            if(action > state[i])
                continue;
            state[i] -= action;
            bool result;
            if(calculated({state[0], {state[1], state[2]}}))
                result = get({state[0], {state[1], state[2]}});
            else{
                result = r(state, actions);
                dict[{state[0], {state[1], state[2]}}] = result;
            }
            state[i] += action;
            if(result == false)
                return true;
        }
    }
    return false;
}

int main() {
    vector<int> state (3, 0);
    for (int i = 0; i < 3; i++)
        cin >> state[i];
    
    int k;
    cin >> k;
    vector<int> actions (k, 0);
    for (int i = 0; i < k; i++)
        cin >> actions[i];
    
    cout << (r(state, actions) ? "Peter" : "Vasya");
}