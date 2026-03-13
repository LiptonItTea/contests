#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Entry {
    int i, j, l, r;
};

bool check(vector<string>& field, vector<vector<bool>>& visited, deque<Entry>& entries, int i0, int j0, int l0, int r0, int l, int r, bool front){
    if(i0 >= 0 && j0 >= 0 && i0 < field.size() && j0 < field[0].size()){
        if(field[i0][j0] == '*')
            return false;
        
        if(visited[i0][j0])
            return false;
        
        if(l0 > l || r0 > r)
            return false;
        
        if(front){
            entries.push_front({i0, j0, l0, r0});
        }
        else{
            entries.push_back({i0, j0, l0, r0});
        }
        visited[i0][j0] = true;

        return true;
    }
    
    return false;
}

void bfs(vector<string>& field, vector<vector<bool>>& visited, int i0, int j0, int l, int r){
    deque<Entry> entries;
    entries.push_back({i0, j0, 0, 0});
    visited[i0][j0] = true;

    while(!entries.empty()){
        Entry curr = entries.front(); entries.pop_front();

        check(field, visited, entries, curr.i - 1, curr.j, curr.l, curr.r, l, r, true);
        check(field, visited, entries, curr.i + 1, curr.j, curr.l, curr.r, l, r, true);
        check(field, visited, entries, curr.i, curr.j + 1, curr.l, curr.r + 1, l, r, false);
        check(field, visited, entries, curr.i, curr.j - 1, curr.l + 1, curr.r, l, r, false);
    }
}

int main() {
    // freopen("test.txt", "r", stdin);
    // freopen("test.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int r, c;
    cin >> r >> c;

    int x, y;
    cin >> x >> y;

    vector<string> field (n);
    vector<vector<bool>> visited (n, vector<bool> (m));
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        field[i] = s;
    }

    bfs(field, visited, r - 1, c - 1, x, y);

    int counter = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // cout << (visited[i][j] ? '+' : field[i][j]);
            if(visited[i][j])
                counter++;
        }
        // cout << "\n";
    }

    cout << counter;
}