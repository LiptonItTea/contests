#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Compare {
    public:
        bool operator()(pair<int, int> o1, pair<int, int> o2){
            return o2.second > o1.second;
        }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        //pair<int, int>* array = new pair<int, int>[n];
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxheap;
        for (int i = 0; i < n; i++){
            pair<int, int> p;
            p.first = i;
            cin >> p.second;
            //array[i] = p;
            maxheap.push(p);
        }

        list<pair<int, int>> talks;
        pair<int, int> p1 = maxheap.top();
        maxheap.pop();
        pair<int, int> p2 = maxheap.top();
        maxheap.pop();
        while(p1.second > 0 && p2.second > 0){
            p1.second--;
            p2.second--;
            pair<int, int> talk {p1.first + 1, p2.first + 1};
            talks.push_back(talk);

            maxheap.push(p1);
            maxheap.push(p2);
            p1 = maxheap.top();
            maxheap.pop();
            p2 = maxheap.top();
            maxheap.pop();
        }

        cout << "" << talks.size() << "\n";
        for (list<pair<int, int>>::iterator it = talks.begin(); it != talks.end(); it++){
            cout << "" << it->first << " " << it->second << "\n";
        }
    }
}