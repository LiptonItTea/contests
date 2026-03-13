#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    if(k == 1){
        cout << n;
        return 0;
    }

    list<int> divisors;
    bool good = false;
    int newN = n;
    while (newN > 1){
        bool found = false;
        for (int i = 2; i * i <= newN; i++){
            if(newN % i == 0){
                found = true;
                divisors.push_back(i);
                newN /= i;
                if(newN != 1 && divisors.size() + 1 == k){
                    good = true;
                }
                else if(divisors.size() == k){          
                    good = true;
                }
                break;
            }
        }
        if(!found)
            break;
        if(good)
            break;
    }
    if(n == newN){
        if(k == 1){
            cout << newN;
        }
        else{
            cout << -1;
        }
        return 0;
    }
    if(!good)
        cout << -1;
    else{
        for (list<int>::iterator it = divisors.begin(); it != divisors.end(); it++){
            cout << *it << " ";
        }
        if(divisors.size() < k){
            cout << newN;
        }
    }
}