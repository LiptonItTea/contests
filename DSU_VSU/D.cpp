#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class DSU {
    public:
        int* parents;
        int n;

        DSU () {
            n = 26;
            parents = new int[n];
            for (int i = 0; i < n; i++)
                parents[i] = i;
        }

        int getParent(int u){
            return (parents[u] == u) ? (u) : (parents[u] = getParent(parents[u]));
        }

        void unionParents(int u, int v){
            int parentU = getParent(u);
            int parentV = getParent(v);

            if(parentU == parentV)
                return;
            
            parents[parentU] = parentV;
        }

};

int main(){
    int n;
    cin >> n;

    DSU dsu;

    string* data = new string[n];
    
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        data[i] = str;

        set<char> uniqueChars;
        for (int j = 0; j < str.length(); j++)
            uniqueChars.insert(str[j]);
        
        vector<char> uniV;
        uniV.reserve(uniqueChars.size());
        for (auto it = uniqueChars.begin(); it != uniqueChars.end(); it++){
            uniV.push_back(*it);
        }

        for (int j = 0; j < uniV.size() - 1; j++){
            for (int k = j + 1; k < uniV.size(); k++){
                int codeJ = uniV[j] - 'a';
                int codeK = uniV[k] - 'a';

                dsu.unionParents(codeJ, codeK);
            }
        }
    }

    set<int> components;
    for (int i = 0; i < n; i++){
        int code = data[i][0] - 'a';
        components.insert(dsu.getParent(code));
    }

    cout << components.size();
}