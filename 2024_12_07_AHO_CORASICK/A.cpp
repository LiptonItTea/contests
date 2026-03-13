#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct Vertex {
    int id;
    vector<int> links;
    bool leaf;
    set<int> strid;

    int p;
    char pch;
    int link;
    vector<int> go;

    int exit;

    Vertex(int _id, int _p, char _pch) {
        id = _id;
        links.assign(26, -1);
        leaf = false;

        p = _p;
        pch = _pch;
        link = -1;
        go.assign(26, -1);

        exit = -1;
    }
};
vector<Vertex> vertices {Vertex(0, 0, 'a')};

void add_string(int id, string& source) {
    int v = 0;
    for (int i = 0; i < source.size(); i++) {
        int c = source[i] - 'a';
        if (vertices[v].links[c] == -1) {
            vertices.push_back(Vertex(vertices.size(), v, source[i]));
            vertices[v].links[c] = vertices.size() - 1;
        }
        v = vertices[v].links[c];
    }
    vertices[v].leaf = true;
    vertices[v].strid.insert(id);
}

int go(int v, char c);

int get_link(int v) {
    if (vertices[v].link == -1) {
        if (v == 0 || vertices[v].p == 0) {
            vertices[v].link = 0;
        }
        else {
            vertices[v].link = go(get_link(vertices[v].p), vertices[v].pch);
            get_link(vertices[v].link);
            if (vertices[vertices[v].link].leaf)
                vertices[v].exit = vertices[v].link;
            else if (vertices[vertices[v].link].exit != -1)
                vertices[v].exit = vertices[vertices[v].link].exit;
        }
    }

    return vertices[v].link;
}

int go(int v, char c) {
    if (vertices[v].go[c - 'a'] == -1) {
        if (vertices[v].links[c - 'a'] != -1)
            vertices[v].go[c - 'a'] = vertices[v].links[c - 'a'];
        else
            vertices[v].go[c - 'a'] = (v == 0 ? 0 : go(get_link(v), c));
    }
    return vertices[v].go[c - 'a'];
}

void dfs(int curr) {
    get_link(curr);
    for (int i = 0; i < vertices[curr].links.size(); i++) {
        if (vertices[curr].links[i] != -1)
            dfs(vertices[curr].links[i]);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string t;
    cin >> t;

    int n;
    cin >> n;
    vector<bool> found (n, false);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        add_string(i, s);
    }
    dfs(0);

    int v = 0;
    for (int i = 0; i < t.size(); i++) {
        v = go(v, t[i]);

        if (vertices[v].leaf) {
            for (auto it = vertices[v].strid.begin(); it != vertices[v].strid.end(); it++) {
                found[*it] = true;
            }
            vertices[v].strid.clear(); // anti-doubleset of found array
        }
        
        int e = vertices[v].exit;
        while (e != -1) {
            for (auto it = vertices[e].strid.begin(); it != vertices[e].strid.end(); it++) {
                found[*it] = true;
            }
            vertices[e].strid.clear(); // anti-doubleset of found array
            e = vertices[e].exit;
        }
    }

    for (int i = 0; i < n; i++) {
        if (found[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}