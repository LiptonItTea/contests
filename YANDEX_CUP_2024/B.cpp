#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        vector<int> h (n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        
        bool afterPeak = false;
        bool skip = false;
        long long prevIndex = 0;
        long long peakIndex = 0;
        long long counter = 0;
        for (long long i = 1; i < n; i++){
            if(h[i - 1] == h[i]){
                skip = true;
            }
            if(!afterPeak && h[i - 1] > h[i]){
                afterPeak = true;
                peakIndex = i - 1;
            }
            if(afterPeak && h[i - 1] < h[i]){
                if(!skip){
                    long long amount = i - prevIndex;
                    long long left = peakIndex - prevIndex;
                    long long right = amount - left - 1;
                    long long sum = left * right;
                    
                    counter += sum;
                }
                
                prevIndex = i - 1;
                skip = false;
                afterPeak = false;
            }
        }
        if(afterPeak && !skip){
            long long amount = n - prevIndex;
            long long left = peakIndex - prevIndex;
            long long right = amount - left - 1;
            long long sum = left * right;
            counter += sum;
        }

        cout << counter << "\n";
    }
}