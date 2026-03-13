#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    multiset<int> all;
    stack<int> in_stack;
    stack<int> in_gcd;
    stack<int> out_stack;
    stack<int> out_gcd;
    int amount1 = 0;
    for (int i = 0; i < n; i++) {
        string data;
        cin >> data;

        char type = data[0];
        if (type == '+'){
            int length = stoi(data.substr(1));

            all.insert(length);
            in_stack.push(length);
            if (in_gcd.empty())
                in_gcd.push(length);
            else
                in_gcd.push(gcd(in_gcd.top(), length));

            if (length == 1)
                amount1++;
        }
        else if (type == '-') {
            if (out_stack.empty()) {
                while (!in_stack.empty()) { //rebase
                    out_stack.push(in_stack.top());
                    in_stack.pop();
                    in_gcd.pop();
                    if (out_gcd.empty())
                        out_gcd.push(out_stack.top());
                    else
                        out_gcd.push(gcd(out_gcd.top(), out_stack.top()));
                }
            }
            int length = out_stack.top();
            out_stack.pop();
            out_gcd.pop();
            all.erase(all.find(length));

            if (length == 1)
                amount1--;
        }
        else { // ?
            if (out_stack.empty()) {
                while (!in_stack.empty()) { //rebase
                    out_stack.push(in_stack.top());
                    in_stack.pop();
                    in_gcd.pop();
                    if (out_gcd.empty())
                        out_gcd.push(out_stack.top());
                    else
                        out_gcd.push(gcd(out_gcd.top(), out_stack.top()));
                }
            }

            if (amount1 > 0){
                cout << "Y1\n";
                continue;
            }
            
            if (out_gcd.top() == 1){
                cout << "N\n";
                continue;
            }

            if (!in_gcd.empty() && in_gcd.top() == 1) {
                cout << "N\n";
                continue;
            }
            
            if (in_gcd.empty()) {
                if (all.find(out_gcd.top()) != all.end())
                    cout << "Y" << out_gcd.top() << "\n";
                else
                    cout << "N\n";
            }
            else { // both non empty
                int allgcd = gcd(in_gcd.top(), out_gcd.top());
                if (allgcd == 1)
                    cout << "N\n";
                else if (all.find(allgcd) != all.end())
                    cout << "Y" << allgcd << "\n";
                else
                    cout << "N\n";
            }
        }
    }
}