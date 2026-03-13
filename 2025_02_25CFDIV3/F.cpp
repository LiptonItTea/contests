#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> sus;
    sus.push_back({5});

    for (int i = 2; i < 20; i++) {
        vector<int> layer (i, 0);
        layer[0] = sus[sus.size() - 1][0];
        for (int j = 1; j < i - 1; j++) {
            layer[j] = sus[sus.size() - 1][j - 1] ^ sus[sus.size() - 1][j];
        }
        layer[i - 1] = sus[sus.size() - 1][i - 2];

        sus.push_back(layer);
    }

    for (int i = 1; i < 21; i++) {
        for (int j = 0; j < i; j++) {
            cout << sus[i - 1][j] << " ";
        }
        cout << "\n";
    }
}