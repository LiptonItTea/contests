#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareInt(int first, int second) {
    return first > second;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> b (n, 0);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    int result = b[n - 1] - b[0] + 1;
    
    vector<int> spaces (n - 1);
    for (int i = 1; i < n; i++)
        spaces.push_back(b[i] - b[i - 1]);
    
    sort(spaces.begin(), spaces.end(), greater<int>());

    for (int i = 0; i < k - 1; i++)
        result -= spaces[i] - 1;
    
    cout << result;
}