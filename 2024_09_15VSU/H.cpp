#include <iostream>
#include <set>
#include <list>

using namespace std;

class Cassa {
    public:
        int freeTimeStamp;
        int id;
        int x, y;

        bool operator()(const Cassa& c1, const Cassa& c2) const{
            if(c1.freeTimeStamp != c2.freeTimeStamp)
                return c1.freeTimeStamp < c2.freeTimeStamp;
            
            return c1.id < c2.id;
        }
};

int main () {
    int n, m;
    cin >> n >> m;

    int* a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    pair<int, int>* cassir = new pair<int, int>[m];
    for (int i = 0; i < m; i++){
        pair<int, int> c;
        cin >> c.first >> c.second;

        cassir[i] = c;
    }

    set<Cassa, Cassa> times;
    for (int i = 0; i < m; i++){
        Cassa cs;
        cs.freeTimeStamp = 0;
        cs.id = i;
        cs.x = cassir[i].first;
        cs.y = cassir[i].second;
        times.insert(cs);
    }

    list<int> history;
    for (int i = 0; i < n; i++){
        Cassa begin = *times.begin();
        int waste = begin.x + begin.y * a[i];
    
        times.erase(begin);
        begin.freeTimeStamp += waste;
        times.insert(begin);

        history.push_back(begin.id);
    }
    cout << times.rbegin()->freeTimeStamp << "\n";
    for (int i : history){
        cout << i + 1 << " ";
    }
}