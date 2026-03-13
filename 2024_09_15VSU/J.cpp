#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> divs (n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j += i){
            divs[j].push_back(i);
        }
    }

    vector<int> indA (n + 1, 0);
    // int* indA = new int[n + 1];
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        indA[num] = i;
    }

    vector<int> indB (n + 1, 0);
    // int* indB = new int[n + 1];
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        indB[num] = i;
    }

    vector<int> shifts (n , INT_MAX);
    for (int x = 1; x <= n; x++){
        for (int i : divs[x]){
            int j = x / i;

            int shift = indA[i] - indB[j];
            if(shift < 0)
                shift += n;

            shifts[shift] = min(shifts[shift], x);
        }
    }

    for (int i = 0; i < n; i++){
        cout << shifts[i] << "\n";
    }
}