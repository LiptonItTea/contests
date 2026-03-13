#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("search.in", "r", stdin);
    freopen("search.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    // string c = b + "#" + a;
    // vector<int> z (c.size(), 0);
    // vector<int> found;
    // int l = 0;
    // int r = 0;
    // for (int i = 1; i < c.size(); i++) {
    //     if (i <= r)
    //         z[i] = min(r - i + 1, z[i - l]);
    //     while (i + z[i] < c.size() && c[i + z[i]] == c[z[i]])
    //         z[i]++;
    //     if (i + z[i] - 1 > r) {
    //         l = i;
    //         r = i + z[i] - 1;
    //     }

    //     if (z[i] == b.size())
    //         found.push_back(i - b.size() - 1);
    // }

    // cout << found.size() << "\n";
    // for (int i = 0; i < found.size(); i++) {
    //     cout << found[i] + 1 << " ";
    // }

    string c = b + "#" + a;
    vector<int> found;
    vector<int> pi (c.size(), 0);
    for (int i = 1; i < c.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && c[i] != c[j])
            j = pi[j - 1];

        if (c[i] == c[j])
            j++;
        pi[i] = j;

        if (pi[i] == b.size())
            found.push_back(i - 2 * b.size());
    }

    cout << found.size() << "\n";
    for (int i = 0; i < found.size(); i++) {
        cout << found[i] + 1 << " ";
    }
}