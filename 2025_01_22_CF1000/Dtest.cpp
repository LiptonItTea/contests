#include <bits/stdc++.h>

using namespace std;

vector<int> k;

int f()
{
    k.push_back(3);
    return 3;
}

int main()
{
    k.push_back(1);
    k[0] = f();
    cout << k[0];
}