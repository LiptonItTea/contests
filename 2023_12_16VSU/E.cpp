#include <iostream>

using namespace std;

int main(){
    long long n, k, a, b;
    cin >> n >> k >> a >> b;

    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }

    long long lastLevel = 0;
    if(n % 10 >= a)
        if(n >= 10 || a != 0)
            lastLevel++;
    if(n % 10 >= b)
        lastLevel++;

    if(k - lastLevel <= 0){
        long long curr = n;
        curr -= curr % 10;
        if(k == 2){
            curr += min(a, b);
        }
        else{ // k == 1
            if(lastLevel == 1){
                curr += min(a, b);
            }
            else{//lastLevel == 2
                curr += max(a, b);
            }
        }
        cout << curr;
        return 0;
    }

    long long levels = (k - lastLevel) / 2;
    long long rest = (k - lastLevel) % 2;
    long long curr = n - 10 * levels;

    if(rest != 0){
        if(curr < 10){
            cout << -1;
            return 0;
        }


        curr -= 10;
        curr -= curr % 10;
        curr += max(a, b);
    }
    else{
        if(curr < 0){
            cout << -1;
            return 0;
        }

        curr -= curr % 10;
        curr += min(a, b);
    }

    if(curr == 0)
        cout << -1;
    else
        cout << curr;
}