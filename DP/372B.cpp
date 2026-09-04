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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m, q;
    cin >> n >> m >> q;

    vector<string> field (n);
    for (int i = 0; i < n; i++)
        cin >> field[i];

    vector<vector<int>> pref2 (n + 1, vector<int> (m + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            pref2[i + 1][j + 1] = pref2[i + 1][j] + pref2[i][j + 1] - pref2[i][j] + (field[i][j] == '0' ? 1 : 0);

    vector<vector<vector<vector<int>>>> is_rect (n + 1, vector<vector<vector<int>>> (m + 1, vector<vector<int>> (n + 1, vector<int> (m + 1))));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = i; k < n; k++)
                for(int l = j; l < m; l++)
                    if (pref2[k + 1][l + 1] - pref2[k + 1][j] - pref2[i][l + 1] + pref2[i][j] == (k - i + 1) * (l - j + 1))
                        is_rect[i + 1][j + 1][k + 1][l + 1]++;

    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                for(int l = 0; l < m; l++)
                    is_rect[i][j + 1][k + 1][l + 1] += is_rect[i + 1][j + 1][k + 1][l + 1];

    for (int j = m - 1; j >= 0; j--)
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                for(int l = 0; l < m; l++)
                    is_rect[i + 1][j][k + 1][l + 1] += is_rect[i + 1][j + 1][k + 1][l + 1];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for(int l = 0; l < m; l++)
                    is_rect[i + 1][j + 1][k + 1][l + 1] += is_rect[i + 1][j + 1][k][l + 1];

    for(int l = 0; l < m; l++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < n; k++)
                    is_rect[i + 1][j + 1][k + 1][l + 1] += is_rect[i + 1][j + 1][k + 1][l];
    

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << is_rect[a][b][c][d] << "\n";
    }
}