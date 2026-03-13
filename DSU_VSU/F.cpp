#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //calculate left bounds
    int* l = new int[n];
    stack<int> s;
    for (int i = 0; i < n; i++){
        while(!s.empty() && a[s.top()] >= a[i]){
            s.pop();
        }
        if(!s.empty()){
            l[i] = s.top();
        }
        else{
            l[i] = -1;
        }
        s.push(i);
    }

    //calculate right bounds
    int* r = new int[n];
    stack<int> sr;
    for (int i = n - 1; i >= 0; i--){
        while(!sr.empty() && a[sr.top()] >= a[i]){
            sr.pop();
        }
        if(!sr.empty()){
            r[i] = sr.top();
        }
        else{
            r[i] = n;
        }
        sr.push(i);
    }

    //count lens and get maximums
    int* ans = new int[n + 1];
    fill(ans, ans + n + 1, 0);

    for (int i = 0; i < n; i++){
        int len = r[i] - l[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }

    //we counted only edges for answers
    //because, for example, for length=7 answer will be 2, for length=10 answer will be 1
    //but we have x=8/9, so we must fill all answers after 2 with 1.
    for (int i = n - 1; i >= 1; i--){
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = 1; i < n + 1; i++){
        cout << ans[i] << " ";
    }
}