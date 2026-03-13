#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>

using namespace std;

float eps = 0.00001;

int main() {
    int m, n;
    long long r;
    cin >> m >> n >> r;

    set<float> c;
    for (int i = 0; i < m; i++){
        float num;
        cin >> num;

        c.insert(num);
    }
    
    set<float> x;
    vector<float> xArr; xArr.reserve(n);
    for (int i = 0; i < n; i++){
        float num;
        cin >> num;

        x.insert(num);
        xArr.push_back(num);
    }

    //  reporter    camLX    camRX
    map<float, pair<float, float>> potential;
    for (auto it = x.begin(); it != x.end(); it++){
        float possX = *it;

        float D = (r - 1) * (r + 1);
        float cLeft = possX - sqrt(D);
        float cRight = possX + sqrt(D);

        auto leftIt = c.lower_bound(cLeft);
        auto rightIt = c.lower_bound(cRight);
        if(*rightIt > cRight){
            rightIt--;
        }
        potential[possX] = {leftIt == c.end() ? -1 : *leftIt, rightIt == c.end() ? -1 : *rightIt};
    }

    float dist = 0;
    float currCVal = *c.begin();
    for (int i = 0; i < n; i++){
        float x = xArr[i];
        float camL = potential[x].first;
        float camR = potential[x].second;
        if(camL > 0 && camR > 0 && camL <= currCVal && currCVal <= camR){
            continue;
        }
        if(camL > 0 && camR < 0 && camL <= currCVal){
            continue;
        }
        if(camR > 0 && camL < 0 && currCVal <= camR){
            continue;
        }

        float newCVal;
        if(x < currCVal){
            newCVal = potential[x].second;
        }
        else{
            newCVal = potential[x].first;
        }
        dist += abs(currCVal - newCVal);
        currCVal = newCVal;
    }

    cout << dist;
}