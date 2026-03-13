#include <iostream>
#include <algorithm>

using namespace std;

struct Exer {
    int t;
    int n;
    char type;
};

bool compare_exer(Exer e1, Exer e2){
    if(e1.type == e2.type){
        return e1.t < e2.t;
    }
    else{
        return e1.type > e2.type;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    Exer* data = new Exer[n];
    int physSize = 0;
    for (int i = 0; i < n; i++){
        Exer e;
        cin >> e.t >> e.n >> e.type;
        data[i] = e;
        if(e.type == 'P')
            physSize++;
    }

    sort(data, data + n, compare_exer);

    int curRes = t;
    long sumPhys = 0;
    long sumMath = 0;
    for (int i = 0; i < n; i++){
        if(curRes - data[i].t * data[i].n > 0){
            curRes -= data[i].t * data[i].n;
            if(data[i].type == 'P')
                sumPhys += data[i].n;
            else
                sumMath += data[i].n;
        }
        else{
            int partN = curRes / data[i].t;
            curRes -= data[i].t * partN;
            
            if(data[i].type == 'P')
                sumPhys += partN;
            else
                sumMath += partN;
            if(data[i].type == 'P'){//jump to math
                i = physSize - 1;
                continue;
            }
            break;
        }
    }
    cout << sumPhys << " " << sumMath;
}