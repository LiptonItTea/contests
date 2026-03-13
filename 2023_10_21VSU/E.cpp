#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    string recipe;
    cin >> recipe;
    int ab = 0,
        as = 0,
        ac = 0;
    for (int i = 0; i < recipe.length(); i++){
        if(recipe[i] == 'B'){
            ab++;
        }
        else if(recipe[i] == 'S'){
            as++;
        }
        else{
            ac++;
        }
    }

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    long long r;
    cin >> r;

    long long left = 0;
    long long right = max((long long) (max(ab, max(as, ac)) - min(nb, min(ns, nc))) * max(pb, max(ps, pc)), 1000 * r);
    long long k = (right + left) / 2;
    unordered_map<int, bool> map;
    while(true){
        long long overprice = 0;
        overprice += max(0ll, (k * ab - nb) * pb);
        overprice += max(0ll, (k * as - ns) * ps);
        overprice += max(0ll, (k * ac - nc) * pc);
        if(overprice <= r){
            map[k] = true;
        }
        else{
            map[k] = false;
        }

        if(map.find(k + 1) != map.end() && map[k] == true && map[k + 1] == false){
            break;
        }
        if(map.find(k - 1) != map.end() && map[k - 1] == true && map[k] == false){
            k--;
            break;
        }

        if(map[k] == true){
            left = k;
        }
        else{
            right = k;
        }

        k = (right + left) / 2;
    }

    cout << k;
}