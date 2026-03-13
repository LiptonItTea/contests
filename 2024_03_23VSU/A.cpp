#include <iostream>

using namespace std;

bool dfsCycle(int** table, bool* visited, bool* checked, int n, int prevN, int curr){
    checked[curr] = true;
    visited[curr] = true;
    for (int i = 0; i < n; i++){
        if(table[curr][i] != INT_MAX){
            if(i == prevN)
                continue;
            
            if(visited[i]){
                return true;
            }
            
            bool result = dfsCycle(table, visited, checked, n, curr, i);
            if(result)
                return true;
        }
    }
    visited[curr] = false;
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    int** table = new int*[n];
    for (int i = 0; i < n; i++){
        table[i] = new int[n];
        for (int j = 0; j < n; j++)
            table[i][j] = INT_MAX;
    }

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        table[a - 1][b - 1] = 1;
        table[b - 1][a - 1] = 1;
    }

    if(m != n - 1){
        cout << "no";
        return 0;
    }

    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    bool* checked = new bool[n];
    for (int i = 0; i < n; i++){
        checked[i] = false;
    }

    bool result = dfsCycle(table, visited, checked, n, -1, 0);
    if(result){
        cout << "no";
        return 0;
    }

    bool visitedAll = true;
    for (int i = 0; i < n; i++){
        if(!checked[i]){
            visitedAll = false;
            break;
        }
    }
    if(!visitedAll){
        cout << "no";
    }
    else{
        cout << "yes";
    }
}