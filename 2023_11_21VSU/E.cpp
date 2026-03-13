#include <iostream>
#include <map>

using namespace std;

int dfs(int curr, int n, int k, int maxAmount, int*** matrix, int maxCost, int currCost){
    if(k > 0){
        for (int i = 0; i < n; i++){
            if(matrix[curr][i][0] != INT_MAX){
                int newCost = currCost;
                //find max
                int maxBagCost = INT_MIN;
                int maxBagIndex = -1;
                for (int j = 0; j < maxAmount; j++){
                    if(matrix[curr][i][j] > maxBagCost){
                        maxBagCost = matrix[curr][i][j];
                        maxBagIndex = j;
                    }
                }
                matrix[curr][i][maxBagIndex] = 0;
                matrix[i][curr][maxBagIndex] = 0;
                newCost += maxBagCost;

                int newMaxCost = dfs(i, n, k - 1, maxAmount, matrix, maxCost, newCost);

                matrix[curr][i][maxBagIndex] = maxBagCost;
                matrix[i][curr][maxBagIndex] = maxBagCost;
                maxCost = max(maxCost, newMaxCost);
            }
        }
    }
    maxCost = max(maxCost, currCost);
    return maxCost;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;


    int** data = new int*[m];
    map<pair<int, int>, int> occs;
    int maxAmount = INT_MIN;
    for (int i = 0; i < m; i++){
        data[i] = new int[3];
        cin >> data[i][0] >> data[i][1] >> data[i][2];
        pair<int, int> p;
        if(data[i][0] >= data[i][1]){
            p.first = data[i][0];
            p.second = data[i][1];
        }
        else{
            p.first = data[i][1];
            p.second = data[i][0];
        }
        occs[p]++;
        maxAmount = max(maxAmount, occs[p]);
    }

    
    int*** matrix = new int**[n];
    for (int i = 0; i < n; i++){
        matrix[i] = new int*[n];
        for (int j = 0; j < n; j++){
            matrix[i][j] = new int[maxAmount];
            for (int k = 0; k < maxAmount; k++){
                matrix[i][j][k] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < m; i++){
        int a = data[i][0];
        int b = data[i][1];
        int c = data[i][2];

        if(matrix[a - 1][b - 1][0] == INT_MAX){
            for (int i = 0; i < maxAmount; i++){
                matrix[a - 1][b - 1][i] = 0;
                matrix[b - 1][a - 1][i] = 0;
            }
        }

        for (int i = 0; i < maxAmount; i++){
            if(matrix[a - 1][b - 1][i] == 0){
                matrix[a - 1][b - 1][i] = c;
                matrix[b - 1][a - 1][i] = c;
                break;
            }
        }
    }

    int maxCost = dfs(0, n, k, maxAmount, matrix, INT_MIN, 0);
    cout << maxCost;
}