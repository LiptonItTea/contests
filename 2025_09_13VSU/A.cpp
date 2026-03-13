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

    int n;
    cin >> n;

    vector<int> divs {1, 5, 10, 20, 100};

    int result = 0;
    for (int i = divs.size() - 1; i >= 0; i--) {
        result += n / divs[i];
        n -= n / divs[i] * divs[i];
    }

    cout << result;
}