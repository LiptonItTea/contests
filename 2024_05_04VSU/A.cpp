#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int ih, il;
    cin >> ih >> il;

    double h = (double) ih,
            l = (double) il;
    
    double x = (l * l - h * h)/2/h;
    printf("%.9f", x);
}