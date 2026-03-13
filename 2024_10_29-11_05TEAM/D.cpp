#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Entry {
    int i;
    long long a;
    int l;
};

bool compareA(Entry& e1, Entry& e2) {
    return e1.a > e2.a;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<Entry> servers;
    vector<Entry> low, high;
    for (int i = 0; i < n; i++) {
        long long a;
        int l;
        cin >> a >> l;

        servers.push_back({i, a, l});
        if (l == 1)
            low.push_back({i, a, l});
        else
            high.push_back({i, a, l});
    }

    //count r
    sort(servers.begin(), servers.end(), compareA);
    int r;
    long long currM = 0;
    for (int i = 0; i < n; i++) {
        currM += servers[i].a;
        if (currM >= m){
            r = i + 1;
            break;
        }
    }

    //count w
    sort(low.begin(), low.end(), compareA);
    sort(high.begin(), high.end(), compareA);
    int size = min(r, (int) low.size());
    int c;
    int left = 0;
    int right = 2 * size;
    vector<int> memory (size + 1, -1);
    while (true) {
        c = (left + right) / 2;
        long long currMc = 0;
        for (int i = 0; i < c; i++) {
            currMc += low[i].a;
        }
        for (int i = 0; i < (r - c); i++) {
            currMc += high[i].a;
        }

        if (currMc >= m)
            memory[c] = 1;
        else
            memory[c] = 0;
        
        if (memory[c] == 1 && c == size)
            break;
        if (c == 0)
            break;
        if (memory[c - 1] == 1 && memory[c] == 0){
            c--;
            break;
        }
        if (memory[c] == 1 && memory[c + 1] == 0)
            break;
        
        if (memory[c])
            left = c;
        else
            right = c;
    }

    cout << r << " " << c << "\n";
    for (int i = 0; i < c; i++) {
        cout << low[i].i + 1 << " ";
    }
    for (int i = 0; i < (r - c); i++) {
        cout << high[i].i + 1 << " ";
    }
}