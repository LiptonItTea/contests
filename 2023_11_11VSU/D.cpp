#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    long long* offsets = new long long[n];
    long long currOffset = 0;
    for (int i = 0; i < n; i++){
        long long curr;
        cin >> curr;

        currOffset += curr;
        offsets[i] = currOffset;
    }

    for (int i = 0; i < m; i++){
        long long b;
        cin >> b;

        int l = 0;
        int r = n;
        int mid = (r + l) / 2;
        while(true){
            if(mid == 0 && b <= offsets[mid]){
                break;
            }
            if(offsets[mid - 1] < b && b <= offsets[mid]){
                break;
            }
            if(offsets[mid] < b && b <= offsets[mid + 1]){
                mid++;
                break;
            }

            if(b < offsets[mid]){
                r = mid;
            }
            else{
                l = mid;
            }
            mid = (r + l) / 2;
        }

        long long lock = b;
        if(mid > 0){
            lock -= offsets[mid - 1];
        }
        cout << mid + 1 << " " << lock << "\n";
    }
}