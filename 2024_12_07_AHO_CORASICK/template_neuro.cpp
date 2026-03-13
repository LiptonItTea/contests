#include <iostream>
#include <vector>
#include <array>
using namespace std;

// Aho-Corasick automaton for multiple-pattern string matching
// - Supports lowercase 'a'..'z' by default (ALPHA = 26)
// - addPattern: insert a pattern with its id
// - build: construct failure links and output links
// - search: find all occurrences of added patterns in a text

struct AhoCorasick {
    static constexpr int ALPHA = 26;

    struct Node {
        array<int, ALPHA> next;
        int link;               // failure link
        vector<int> out;        // pattern IDs ending at this node
        Node() : link(-1) {
            next.fill(-1);
        }
    };

    vector<Node> trie;

    AhoCorasick() {
        trie.emplace_back();  // root node = 0
    }

    // Add a pattern string, associate with id, returns end-node index
    int addPattern(const string &s, int id) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].out.push_back(id);
        return v;
    }

    // Build failure links and propagate output lists
    void build() {
        queue<int> q;
        trie[0].link = 0;
        // Initialize depth-1 nodes
        for (int c = 0; c < ALPHA; ++c) {
            if (trie[0].next[c] != -1) {
                trie[ trie[0].next[c] ].link = 0;
                q.push(trie[0].next[c]);
            } else {
                trie[0].next[c] = 0;
            }
        }
        // BFS
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int c = 0; c < ALPHA; ++c) {
                int u = trie[v].next[c];
                if (u != -1) {
                    trie[u].link = trie[ trie[v].link ].next[c];
                    // merge output links
                    auto &out_u = trie[u].out;
                    auto &out_link = trie[ trie[u].link ].out;
                    out_u.insert(out_u.end(), out_link.begin(), out_link.end());
                    q.push(u);
                } else {
                    trie[v].next[c] = trie[ trie[v].link ].next[c];
                }
            }
        }
    }

    // Search text; returns vector of (end_index, pattern_id)
    vector<pair<int,int>> search(const string &text) const {
        vector<pair<int,int>> results;
        int v = 0;
        for (int i = 0; i < (int)text.size(); ++i) {
            int c = text[i] - 'a';
            v = trie[v].next[c];
            for (int pid : trie[v].out) {
                results.emplace_back(i, pid);
            }
        }
        return results;
    }
};

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string text;
    cin >> n;
    vector<string> patterns(n);
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }
    cin >> text;

    AhoCorasick ac;
    for (int i = 0; i < n; i++) {
        ac.addPattern(patterns[i], i);
    }
    ac.build();

    auto matches = ac.search(text);
    // print matches: pattern id and ending position
    for (auto &m : matches) {
        int pos = m.first;
        int id  = m.second;
        cout << "Pattern #" << id << " ends at index " << pos << '\n';
    }
    return 0;
}
