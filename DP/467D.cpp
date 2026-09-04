#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

int count_r(string& s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'r' || s[i] == 'R')
            result++;

    return result;
}

void topsort(int curr, vector<vector<int>>& links, vector<bool>& visited, vector<int>& result) {
    visited[curr] = true;

    for (int next : links[curr]) {
        if (visited[next])
            continue;
        
        topsort(next, links, visited, result);
    }

    result.push_back(curr);
}

int best_id = -1;
int best_r = INT_MAX;
int best_size = INT_MAX;
void dfs(int curr, int comp, vector<vector<int>>& inv_links, vector<int>& condensed, vector<vector<int>>& cond_links, vector<int>& r, vector<int>& size) {
    condensed[curr] = comp;
    if (best_r > r[curr] || (best_r == r[curr] && best_size > size[curr])) {
        best_id = curr;
        best_r = r[curr];
        best_size = size[curr];
    }

    for (int next : inv_links[curr]) {
        if (condensed[next] != -1){
            if (condensed[next] != comp)
                cond_links[condensed[next]].push_back(comp);
            continue;
        }
        
        dfs(next, comp, inv_links, condensed, cond_links, r, size);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int m;
    cin >> m;
    map<string, int> ids;
    vector<string> source;
    vector<int> r;
    vector<int> size;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return tolower(c);});

        source.push_back(s);
        
        if (ids.find(s) != ids.end())
            continue;

        ids[s] = ids.size();
        r.push_back(count_r(s));
        size.push_back(s.size());
    }

    int n;
    cin >> n;

    vector<vector<int>> links (ids.size());
    for (int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;

        transform(u.begin(), u.end(), u.begin(), [](unsigned char c) {return tolower(c);});
        transform(v.begin(), v.end(), v.begin(), [](unsigned char c) {return tolower(c);});

        if (ids.find(u) == ids.end()){
            ids[u] = ids.size();
            r.push_back(count_r(u));
            size.push_back(u.size());
            links.push_back({});
        }
        if (ids.find(v) == ids.end()){
            ids[v] = ids.size();
            r.push_back(count_r(v));
            size.push_back(v.size());
            links.push_back({});
        }
        
        links[ids[u]].push_back(ids[v]);
    }

    vector<int> ts;
    vector<bool> visited (links.size(), false);
    for (int i = 0; i < links.size(); i++)
        if (!visited[i])
            topsort(i, links, visited, ts);

    reverse(ts.begin(), ts.end());

    vector<vector<int>> inv_links(links.size());
    for (int i = 0; i < links.size(); i++)
        for (int j = 0; j < links[i].size(); j++)
            inv_links[links[i][j]].push_back(i);

    vector<int> condensed (links.size(), -1);
    vector<int> result;
    vector<vector<int>> cond_links;
    int components = 0;
    for (int i = 0; i < ts.size(); i++) {
        if (condensed[ts[i]] == -1) {
            cond_links.push_back({});
            dfs(ts[i], components, inv_links, condensed,cond_links, r, size);

            result.push_back(best_id);

            best_id = -1;
            best_r = INT_MAX;
            best_size = INT_MAX;
            components++;
        }
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        int curr_best = result[i];
        for (int next : cond_links[i]) {
            int next_best = result[next];

            if (r[curr_best] > r[next_best] || (r[curr_best] == r[next_best] && size[curr_best] > size[next_best]))
                curr_best = next_best;
        }
        result[i] = curr_best;
    }

    ll result_r = 0;
    ll result_size = 0;
    for (string s : source) {
        int node_id = ids[s];
        int condense_id = condensed[node_id];

        result_r += r[result[condense_id]];
        result_size += size[result[condense_id]];
    }

    cout << result_r << " " << result_size;
}