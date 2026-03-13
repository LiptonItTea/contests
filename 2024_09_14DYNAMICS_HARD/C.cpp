#include <iostream>
#include <vector>

using namespace std;

long long n, b;

long long maxR = LLONG_MIN;
void recurseSearch(vector<vector<pair<long long, long long>>>& data, int index, long long totalR, long long totalE){
    maxR = max(maxR, totalR);
    if(index < data.size() - 1){
        recurseSearch(data, index + 1, totalR, totalE);
    }
    for (int i = 0; i < data[index].size(); i++){
        if(totalE + data[index][i].second <= b){
            long long newTotalE = data[index][i].second + totalE;
            long long newTotalR = data[index][i].first + totalR;

            maxR = max(maxR, newTotalR);
            if(index < data.size() - 1){
                recurseSearch(data, index + 1, newTotalR, newTotalE);
            }
        }
    }
}

int main() {
    cin >> n >> b;

    vector<vector<pair<long long, long long>>> data (n);
    for (int i = 0; i < n; i++){
        long long k;
        cin >> k;
        for (int j = 0; j < k; j++){
            long long r, e;
            cin >> r >> e;

            data[i].push_back({r, e});
        }
    }

    recurseSearch(data, 0, 0, 0);
    cout << maxR;
}