#include <iostream>
#include <unordered_map>

using namespace std;

class Equal {
    public:
        bool operator()(pair<int, int> o1, pair<int, int> o2){
            return o1.second == o2.second;
        }
};

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, s;
        cin >> n >> s;

        int* array = new int[n];
        for (int i = 0; i < n; i++){
            cin >> array[i];
        }

        //найти минимальный среди prefA
        //чем дальше prefA, тем он больше
        int maxLen = INT_MIN;

        int prefSum = 0;
        //sum - index (only unique sums, that means that our sum would be first)
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < n; i++){
            prefSum += array[i];
            //found sum
            if(map.find(prefSum - s) != map.end()){
                int prefAIndex = map[prefSum - s];
                if(i - prefAIndex + 1 > maxLen){
                    maxLen = i - prefAIndex;
                }
            }
            //unique means first encounter
            if(array[i] > 0){
                map[prefSum] = i;
            }
        }
        if(maxLen == INT_MIN)
            cout << "" << -1 << "\n";
        else
            cout << "" << n - maxLen << "\n";
    }
}