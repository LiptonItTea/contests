#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m;
map<int, int> amounts;
int maxNum = INT_MIN;
int minNum = INT_MAX;
bool dfs(vector<vector<int>>& field, vector<vector<char>>& type, int ci, int cj, int pi, int pj, int depth){
    if(depth == amounts[field[ci][cj]]){
        type[ci][cj] = 'E';
        return true;
    }

    bool good = false;
    if(ci > 0 && (ci - 1 != pi || cj != pj) && field[ci][cj] == field[ci - 1][cj]){
        bool res = dfs(field, type, ci - 1, cj, ci, cj, depth + 1);
        good = good || res;
    }
    if(ci < n - 1 && (ci + 1 != pi || cj != pj) && field[ci][cj] == field[ci + 1][cj]){
        bool res = dfs(field, type, ci + 1, cj, ci, cj, depth + 1);
        good = good || res;
    }
    if(cj > 0 && (ci != pi || cj - 1 != pj) && field[ci][cj] == field[ci][cj - 1]){
        bool res = dfs(field, type, ci, cj - 1, ci, cj, depth + 1);
        good = good || res;
    }
    if(cj < m - 1 && (ci != pi || cj + 1 != pj) && field[ci][cj] == field[ci][cj + 1]){
        bool res = dfs(field, type, ci, cj + 1, ci, cj, depth + 1);
        good = good || res;
    }

    if(good){
        if(depth == 1){
            type[ci][cj] = 'E';
        }
        else{
            type[ci][cj] = 'M';
        }

        return true;
    }
    return false;
}

void possibleAdvances(vector<vector<int>>& field, vector<vector<char>>& type, vector<pair<int, int>>& posses, int ci, int cj, int value){
    if(ci > 0 && type[ci - 1][cj] == 'E' && value == field[ci - 1][cj]){
        posses.push_back({ci - 1, cj});
    }
    if(ci < n - 1 && type[ci + 1][cj] == 'E' && value == field[ci + 1][cj]){
        posses.push_back({ci + 1, cj});
    }
    if(cj > 0 && type[ci][cj - 1] == 'E' && value == field[ci][cj - 1]){
        posses.push_back({ci, cj - 1});
    }
    if(cj < m - 1 && type[ci][cj + 1] == 'E' && value == field[ci][cj + 1]){
        posses.push_back({ci, cj + 1});
    }
}

//clear path every time you call solver!
vector<pair<int, int>> path;
pair<int, int> findNextEdge(vector<vector<int>>& field, vector<vector<char>>& type, int ci, int cj, int pi, int pj, int skip){
    path.push_back({ci, cj});
    if(type[ci][cj] == 'E'){
        if(skip > 0){
            skip--;
        }
        else{
            pair<int, int> p {ci, cj};
            return p;
        }
    }

    if(ci > 0 && (ci - 1 != pi || cj != pj) && field[ci][cj] == field[ci - 1][cj]){
        return findNextEdge(field, type, ci - 1, cj, ci, cj, skip);
    }
    if(ci < n - 1 && (ci + 1 != pi || cj != pj) && field[ci][cj] == field[ci + 1][cj]){
        return findNextEdge(field, type, ci + 1, cj, ci, cj, skip);
    }
    if(cj > 0 && (ci != pi || cj - 1 != pj) && field[ci][cj] == field[ci][cj - 1]){
        return findNextEdge(field, type, ci, cj - 1, ci, cj, skip);
    }
    if(cj < m - 1 && (ci != pi || cj + 1 != pj) && field[ci][cj] == field[ci][cj + 1]){
        return findNextEdge(field, type, ci, cj + 1, ci, cj, skip);
    }
    
    return {-1, -1};
}

bool solver(vector<vector<int>>& field, vector<vector<char>>& type, int si, int sj){
    int ci = si,
        cj = sj;

    auto curNumIt = amounts.begin();
    while(true){
        pair<int, int> ne = findNextEdge(field, type, ci, cj, -1, -1, amounts[field[ci][cj]] > 1);
        ci = ne.first;
        cj = ne.second;

        //find edges with size = curSize + 1
        vector<pair<int, int>> possibles; auto nextIt = curNumIt; nextIt++;
        possibleAdvances(field, type, possibles, ci, cj, nextIt->first);
        
        if(possibles.size() == 0){
            if(field[ci][cj] == maxNum){
                return true;
            }
            return false;
        }
        if(possibles.size() == 1){
            ci = possibles[0].first;
            cj = possibles[0].second;
        }
        if(possibles.size() == 2){
            if(nextIt->first == maxNum){
                ci = possibles[0].first;
                cj = possibles[0].second;
            }
            else{
                for (pair<int, int> poss : possibles){
                    vector<pair<int, int>> nextPossibles; auto afterNextIt = nextIt; afterNextIt++;
                    possibleAdvances(field, type, nextPossibles, poss.first, poss.second, afterNextIt->first);
                    
                    if(nextPossibles.size() == 0){
                        ci = poss.first;
                        cj = poss.second;
                        break;
                    }
                }
            }
        }
        curNumIt++;
    }

    return false;
}

int main() {
    
    cin >> n >> m;

    vector<vector<int>> field (n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> field[i][j];
            amounts[field[i][j]]++;
            maxNum = max(maxNum, field[i][j]);
            minNum = min(minNum, field[i][j]);
        }
    }

    vector<vector<char>> type (n, vector<char> (m, '.'));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(type[i][j] != '.'){
                continue;
            }

            bool res = dfs(field, type, i, j, -1, -1, 1);
        }
    }
    //check if everything is calculated
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(type[i][j] == '.'){
                cout << -1;
                return 0;
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << type[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(field[i][j] == minNum && type[i][j] == 'E'){
                path.clear();
                bool res = solver(field, type, i, j);

                if(res && path.size() == n * m){
                    for (pair<int, int> p : path){
                        cout << p.first + 1 << " " << p.second + 1 << "\n";
                    }

                    return 0;
                }
            }
        }
    }

    cout << -1;
}