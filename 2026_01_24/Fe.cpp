#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using ll = long long;

struct Node {
    ll start;
    ll len;
    ll repeat;

    Node(ll s = 0, ll l = 0, ll r = 1) : start(s), len(l), repeat(r) {}
};

class StringManager {
private:
    string orig;
    vector<Node> nodes;

    pair<int, ll> find_node(ll pos) const {
        ll cur = 0;
        for (int i = 0; i < nodes.size(); i++) {
            ll node_len = nodes[i].len * nodes[i].repeat;
            if (pos < cur + node_len) {
                return {i, pos - cur};
            }
            cur += node_len;
        }
        return {-1, 0};
    }

public:
    StringManager(const string& s) : orig(s) {
        nodes.push_back(Node(0, s.size(), 1));
    }

    char get_char(ll pos) const {
        pos--;
        auto [node_idx, offset] = find_node(pos);
        if (node_idx == -1) return '?';

        const Node& node = nodes[node_idx];
        ll char_idx = node.start + (offset / node.repeat);
        return orig[char_idx];
    }

    void duplicate_substring(ll l, ll r) {
        l--; r--; 

        vector<pair<int, ll>> affected;
        ll cur_pos = 0;

        for (int i = 0; i < nodes.size(); i++) {
            ll node_len = nodes[i].len * nodes[i].repeat;
            ll node_start = cur_pos;
            ll node_end = cur_pos + node_len - 1;

            if (node_end >= l && node_start <= r) {
                affected.push_back({i, cur_pos});
            }

            cur_pos += node_len;
        }

        vector<Node> new_nodes;
        cur_pos = 0;

        for (int i = 0; i < nodes.size(); i++) {
            ll node_len = nodes[i].len * nodes[i].repeat;
            ll node_start = cur_pos;
            ll node_end = cur_pos + node_len - 1;

            if (node_end < l || node_start > r) {
                new_nodes.push_back(nodes[i]);
            } else if (l <= node_start && node_end <= r) {
                Node new_node = nodes[i];
                new_node.repeat *= 2;
                new_nodes.push_back(new_node);
            } else {
                if (node_start < l) {
                    ll before_len = (l - node_start) / nodes[i].repeat;
                    if (before_len > 0) {
                        new_nodes.push_back(Node(nodes[i].start, before_len, nodes[i].repeat));
                    }
                }

                ll inside_start = max(node_start, l);
                ll inside_end = min(node_end, r);
                ll inside_len_in_chars = (inside_end - inside_start + 1) / nodes[i].repeat;
                if (inside_len_in_chars > 0) {
                    ll char_offset = (inside_start - node_start) / nodes[i].repeat;
                    Node inside_node(nodes[i].start + char_offset, inside_len_in_chars, nodes[i].repeat * 2);
                    new_nodes.push_back(inside_node);
                }

                if (node_end > r) {
                    ll after_start_in_chars = (r + 1 - node_start) / nodes[i].repeat;
                    if (after_start_in_chars < nodes[i].len) {
                        Node after_node(nodes[i].start + after_start_in_chars,
                                        nodes[i].len - after_start_in_chars,
                                        nodes[i].repeat);
                        new_nodes.push_back(after_node);
                    }
                }
            }

            cur_pos += node_len;
        }

        nodes = new_nodes;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    StringManager manager(s);

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            ll l, r;
            cin >> l >> r;
            manager.duplicate_substring(l, r);
        } else {
            ll i;
            cin >> i;
            cout << manager.get_char(i) << '\n';
        }
    }

    return 0;
}