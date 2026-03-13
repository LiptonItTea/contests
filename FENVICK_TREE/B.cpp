#include <iostream>
#include <vector>

using namespace std;

struct FenTree {
    int width, height, depth;
    vector<vector<vector<int>>> t;

    FenTree(vector<vector<vector<int>>>& source) {
        height = source.size();
        width = source[0].size();
        depth = source[0][0].size();

        t.assign(height, vector<vector<int>> (width, vector<int> (depth, 0)));

        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                for (int k = 0; k < depth; k++)
                    inc(i, j, k, source[i][j][k]);
    }

    void inc(int y, int x, int z, int value) {
        for (int i = y; i < height; i = i | (i + 1))
            for (int j = x; j < width; j = j | (j + 1))
                for (int k = z; k < depth; k = k | (k + 1))
                    t[i][j][k] += value;
    }

    int sum(int y, int x, int z) {
        int result = 0;
        for (int i = y; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = x; j >= 0; j = (j & (j + 1)) - 1)
                for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
                    result += t[i][j][k];
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("stars.in", "r", stdin);
    freopen("stars.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<vector<int>>> source (n, vector<vector<int>> (n, vector<int> (n, 0)));
    FenTree ft (source);

    while (true) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y, z, k;
            cin >> x >> y >> z >> k;

            ft.inc(y, x, z, k);
        }
        if (type == 2) {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            x1--; y1--; z1--;

            cout << ft.sum(y2, x2, z2)
                    - ft.sum(y2, x2, z1) - ft.sum(y1, x2, z2) -  ft.sum(y2, x1, z2)
                    + ft.sum(y2, x1, z1) + ft.sum(y1, x2, z1) + ft.sum(y1, x1, z2)
                    - ft.sum(y1, x1, z1) << "\n";
        }
        if (type == 3) {
            break;
        }
    }
}