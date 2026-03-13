#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_map<string, list<string>> map;
    string data;
    getline(cin, data);
    for (int i = 0; i < n; i++){
        getline(cin, data);

        string author;
        string name;
        for (int j = 0; j < data.length(); j++){
            if(data[j] == ' '){
                author = data.substr(0, j);
                name = data.substr(j + 1, data.length() - j);
                map[author].push_back(name);
                break;
            }
        }
    }
    list<string> allBooks;
    for (unordered_map<string, list<string>>::iterator it = map.begin(); it != map.end(); it++){
        list<string> books = it->second;
        if(books.size() > 1){
            continue;
        }
        for (string name : books){
            allBooks.push_back(name);
        }
    }
    cout << allBooks.size() << "\n";
    for (string name : allBooks){
        cout << name << "\n";
    }
}