#include <iostream>
#include <map>

map<pair<int, int>, int> cache;
int recurse(int n, int depth){
    if(cache.find({n, depth}) != cache.end()){
        return cache[{n, depth}];
    }

    if(depth % 2 == 0){
        if(n == 1 || n == 2){
            return 0;
        }
    }
    else{
        if(n == 1 || n == 2){
            return 1;
        }
    }

    int counter = 0;
    for (int i = 1; 2 * i < n; i++){
        recurse(i);
    }
}

using namespace std;

int main(){
    freopen("divide-heaps.in", "r", stdin);
    freopen("divide-heaps.out", "w", stdout);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){

    }
}