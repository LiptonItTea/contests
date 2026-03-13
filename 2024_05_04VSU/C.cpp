#include <iostream>
#include <math.h>

using namespace std;

double ZERO_TOLERANCE = 0.00000001;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ivb, ivs;
    cin >> n >> ivb >> ivs;
    double vb = (double) ivb;
    double vs = (double) ivs;
 
    int* stops = new int[n];
    for (int i = 0; i < n; i++){
        cin >> stops[i];
    }

    int ixu, iyu;
    cin >> ixu >> iyu;
    double xu = (double) ixu;
    double yu = (double) iyu;

    double* times = new double[n];
    double* distsFromStop = new double[n];

    double timeSpent = 0;
    for (int i = 1; i < n; i++){
        timeSpent += ((double) (stops[i] - stops[i - 1])) / vb;
        double dist = sqrt(pow(stops[i] - xu, 2) + yu * yu);
        
        times[i] = timeSpent + dist /((double) vs);
        cout << "SPENT: " << timeSpent << " DIST: " << dist / vs << " total: " << times[i] << "\n";
    }
    double mintime = INT_MAX;
    int minind = -1;
    for (int i = 1; i < n; i++){
        if(times[i] < mintime){
            mintime = times[i];
            minind = i;
        }
        else if(abs(mintime - times[i]) < ZERO_TOLERANCE){
            if(time)
        }
    }
    cout << minind + 1;
}