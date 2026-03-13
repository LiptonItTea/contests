#include <vector>
#include <iostream>

using namespace std;

struct FenTree {
    int size;
    vector<int> t;

    FenTree(vector<int>& source) {
        size = source.size();
        t.assign(size, 0);

        for (int i = 0; i < size; i++)
            inc (i, source[i]);
    }

    int h(int i) {
        return i | (i + 1);
    }

    int f(int i) {
        return i & (i + 1);
    }

    void inc (int i, int delta) {
        for (; i < size; i = h(i)) {
            t[i] += delta;
        }
    }

    int sum (int i) {
        int sum = 0;
        for (; i >= 0; i = f(i) - 1) {
            sum += t[i];
        }

        return sum;
    }
};

int main() {
    vector<int> source {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    FenTree ft (source);

    for (int i = 0; i < source.size(); i++) {
        cout << ft.sum(i) << " ";
    }
    cout << "\n";
    ft.inc(9, -1);
    for (int i = 0; i < source.size(); i++) {
        cout << ft.sum(i) << " ";
    }
}