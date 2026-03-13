#include <iostream>
#include <string>

using namespace  std;

int main(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if(k == 1 || k == 2){
        cout << "YES";
        return 0;
    }
    
    //k-1
    //remove left, right and bite
    if((n - k) % (k - 1) == 0){
        bool good = true;
        int dist = (n - k) / (k - 1);
        string prev = s.substr(1, dist);
        for (int i = 1; i < k - 1; i++){
            string curr = s.substr(1 + i * (dist + 1), dist);
            if(prev != curr){
                good = false;
                break;
            }
            prev = curr;
        }
        if(good){
            cout << "YES";
            return 0;
        }
    }
    //k
    //remove left or right
    if((n - k) % k == 0){
        bool good = true;
        int dist = (n - k) / k;
        //remove left
        string prev = s.substr(1, dist);
        for (int i = 1; i < k; i++){
            string curr = s.substr(1 + i * (dist + 1), dist);
            if(prev != curr){
                good = false;
                break;
            }
            prev = curr;
        }
        if(good){
            cout << "YES";
            return 0;
        }
        //remove right
        good = true;
        prev = s.substr(0, dist);
        for (int i = 1; i < k; i++){
            string curr = s.substr(i * (dist + 1), dist);
            if(prev != curr){
                good = false;
                break;
            }
            prev = curr;
        }
        if(good){
            cout << "YES";
            return 0;
        }
    }
    //k+1
    //remove nor left or right
    if((n - k) % (k + 1) == 0){
        bool good = true;
        int dist = (n - k) / (k + 1);
        string prev = s.substr(0, dist);
        for (int i = 1; i < k + 1; i++){
            string curr = s.substr(i * (dist + 1), dist);
            if(prev != curr){
                good = false;
                break;
            }
        }
        if(good){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}