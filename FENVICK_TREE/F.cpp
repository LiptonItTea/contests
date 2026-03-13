#include <iostream>
#include <vector>

using namespace std;

struct FenTree {
    vector<long long> t;
    int size;

    FenTree(int n) {
        size = n;
        t.assign(n, 0);
    }

    void inc(int i, long long value) {
        for (; i < size; i = i | (i + 1))
            t[i] += value;
    }

    long long sum(int i) {
        long long result = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            result += t[i];
        
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("test.in", "r", stdin);
    // cout << "started\n";

    int n, q;
    cin >> n >> q;

    FenTree presence (n + 1);
    FenTree amount (n + 1);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (presence.sum(a) - presence.sum(a - 1) == 0)
            presence.inc(a, 1);
        amount.inc(a, 1);
    }

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        if (k > 0) {
            //adding

            if (presence.sum(k) - presence.sum(k - 1) == 0)
                presence.inc(k, 1);
            amount.inc(k, 1);
        }
        else {
            //remove k-th from sorted set
            k = -k;

            int l = 0;
            int r = n + 1;
            int c;

            while (true) {
                c = (l + r) / 2;
                long long cursum = presence.sum(c);

                if (c > 0 && presence.sum(c - 1) == k - 1 && cursum == k){
                    break;
                }
                if (c < n && cursum == k - 1 && presence.sum(c + 1) == k){
                    c++;
                    break;
                }

                if (cursum >= k)
                    r = c;
                else
                    l = c;
            }

            amount.inc(c, -1);
            if (amount.sum(c) - amount.sum(c - 1) == 0)
                presence.inc(c, -1);
        }
    }

    if (amount.sum(n) == 0){
        cout << 0;
        return 0;
    }

    int l = 0;
    int r = n + 1;
    int c;

    while (true) {
        c = (l + r) / 2;
        long long cursum = presence.sum(c);

        if (c > 0 && presence.sum(c - 1) == 0 && cursum == 1){
            break;
        }
        if (c < n && cursum == 0 && presence.sum(c + 1) == 1){
            c++;
            break;
        }

        if (cursum >= 1)
            r = c;
        else
            l = c;
    }

    cout << c;
}