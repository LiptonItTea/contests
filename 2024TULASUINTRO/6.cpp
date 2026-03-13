#include <iostream>

using namespace std;

int euclid(int n, int m){
    if(m == 0 || n == 0)
        return 1;
    int r = n % m;
    if(r == 0){
        return m;
    }
    return euclid(m, r);
}

int main(){
    int n;
    cin >> n;

    int currP = 0;
    int currQ = 1;
    for (int i = 0; i < n; i++){
        //sum
        int p, q;
        cin >> p >> q;
        if(currQ == q){
            currP += p;
        }
        else{
            currP *= abs(q);
            currP += p * currQ;
            currQ *= abs(q);
        }
        

        //and crop
        if(currP == 0){
            currQ = 1;
        }
        else{
            int nod = euclid(abs(max(currP, currQ)), abs(min(currP, currQ)));
            currP /= nod;
            currQ /= nod;
        }  
    }
    cout << currP << " " << currQ;
}