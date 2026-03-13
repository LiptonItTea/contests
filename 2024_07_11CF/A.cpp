#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int* abc = new int[3];
        for (int i = 0; i < 3; i++)
            cin >> abc[i];

        int maxNum = INT_MIN;
        for (int first = 0; first < 3; first++){
            for (int second = 0; second < 3; second++){
                for (int third = 0; third < 3; third++){
                    for (int fourth = 0; fourth < 3; fourth++){
                        for (int fifth = 0; fifth < 3; fifth++){
                            abc[first]++;
                            abc[second]++;
                            abc[third]++;
                            abc[fourth]++;
                            abc[fifth]++;
                            maxNum = max(maxNum, abc[0] * abc[1] * abc[2]);
                            abc[first]--;
                            abc[second]--;
                            abc[third]--;
                            abc[fourth]--;
                            abc[fifth]--;
                        }
                    }
                }
            }
        }
        cout << maxNum << "\n";
    }
}