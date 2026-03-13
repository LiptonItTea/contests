#include <iostream>
#include <vector>

using namespace std;

long long euclid(long long n, long long m){
    if(n < m){
        long long temp = n;
        n = m;
        m = temp;
    }

    if(m == 0)
        return n;
    if(n % m == 0)
        return m;
    return euclid(m, n % m);
}

class Fract {
    public:
        long long q;
        long long r;

        void trunc(){
            long long k = euclid(abs(q), abs(r));
            q /= k;
            r /= k;
        }

        void add(long long aq, long long ar){
            q = q * ar + aq * r;
            r = r * ar;
            trunc();
        }

        void mult(long long aq, long long ar){
            q *= aq;
            r *= ar;
            trunc();
        }
};

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> coords (n);
    for (int i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;

        coords[i] = {x, y};
    }
    //phase 0 - move 0 point to 0 (with all points)
    int xShift = coords[0].first;
    int yShift = coords[0].second;
    for (int i = 0; i < n; i++){
        coords[i].first -= xShift;
        coords[i].second -= yShift;
    }

    //phase 1 - find all area
    Fract s; s.q = 0; s.r = 2;
    for (int i = 2; i < n; i++){
        long long xa = coords[i - 1].first,
                    ya = coords[i - 1].second;
        long long xb = coords[i].first,
                    yb = coords[i].second;
        
        s.q += abs(xa * yb - xb * ya);
    }

    //phase 2 - find dividing triangle
    Fract sCur; sCur.q = 0; sCur.r = 2;
    int lastIndex;
    for (int i = 2; i < n; i++){
        long long xa = coords[i - 1].first,
                    ya = coords[i - 1].second;
        long long xb = coords[i].first,
                    yb = coords[i].second;
        
        lastIndex = i;
        if(2 * (sCur.q + abs(xa * yb - xb * ya)) <= s.q){
            sCur.q += xa * yb - xb * ya;
        }
        else{
            break;
        }
    }

    //phase 3 - calculate everything
    long long x1 = coords[lastIndex - 1].first,
                y1 = coords[lastIndex - 1].second;
    long long x2 = coords[lastIndex].first,
                y2 = coords[lastIndex].second;
    
    Fract xr = s;
    // if(x1 * y2 - x2 * y1 > 0)
        xr.add(-2 * sCur.q, sCur.r);
    // else{
    //     xr.q *= -1;
    //     xr.add(2 * sCur.q, sCur.r);
    // }
        
    xr.mult(x2 - x1, 1);
    xr.add(-x1 * x2 * y1, 1);
    xr.add(x1 * x1 * y2, 1);
    xr.mult(1, x1 * y2 - y1 * x2);

    Fract yr = xr;
    if(x2 - x1 == 0){
        yr = s;
        // if(x1 * y2 - x2 * y1 > 0)
            yr.add(-2 * sCur.q, sCur.r);
        // else{
        //     yr.q *= -1;
        //     yr.add(2 * sCur.q, sCur.r);
        // }
        yr.add(x1 * y1, 1);
        yr.mult(1, x1);
    }
    else{
        yr.mult(y2 - y1, 1);
        yr.add(x2 * y1, 1);
        yr.add(-x1 * y2, 1);
        yr.mult(1, x2 - x1);
    }

    long long x = xr.q * yr.r;
    long long y = yr.q * xr.r;

    cout << coords[0].first + xShift << " " << coords[0].second + yShift << "\n" << x + xShift << " " << y + yShift;
}