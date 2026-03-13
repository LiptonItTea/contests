#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        string sn = to_string(n);

        vector<pair<int, int>> results;
        for (int a = 1; a <= 10000; a++) {
            int minb = max(1, (int) sn.size() * a - 6);
            int maxb = (int) sn.size() * a - 1;

            for (int b = minb; b <= maxb; b++) {
                string strange_result = "";
                for (int i = 0; i < 6; i++)
                    strange_result += to_string(n);
                while (strange_result.size() > sn.size() * a - b)
                    strange_result.pop_back();
                
                int isr = stoi(strange_result);
                if (isr == n * a - b)
                    results.push_back({a, b});
            }
        }

        cout << results.size() << "\n";
        for (int i = 0; i < results.size(); i++) {
            cout << results[i].first << " " << results[i].second << "\n";
        }
    }
}