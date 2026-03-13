#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool recurseSearch(int index, string& stackWord, char** field, bool** visited, int** indexes, int currX, int currY){
    if(stackWord.length() == 0){
        indexes[currY][currX] = index;
        field[currY][currX] = '.';
        return true;
    }

    if(currY > 0 && field[currY - 1][currX] == stackWord[0] && !visited[currY - 1][currX]){
        char toErase = stackWord[0];
        stackWord.erase(stackWord.begin());
        visited[currY][currX] = true;
        bool result = recurseSearch(index, stackWord, field, visited, indexes, currX, currY - 1);
        if(result){
            indexes[currY][currX] = index;
            field[currY][currX] = '.';
            return true;
        }
        else{
            stackWord.insert(stackWord.begin(), toErase);
            visited[currY][currX] = false;
        }
    }
    if(currY < 7 && field[currY + 1][currX] == stackWord[0] && !visited[currY + 1][currX]){
        char toErase = stackWord[0];
        stackWord.erase(stackWord.begin());
        visited[currY][currX] = true;
        bool result = recurseSearch(index, stackWord, field, visited, indexes, currX, currY + 1);
        if(result){
            indexes[currY][currX] = index;
            field[currY][currX] = '.';
            return true;
        }
        else{
            stackWord.insert(stackWord.begin(), toErase);
            visited[currY][currX] = false;
        }
    }
    if(currX > 0 && field[currY][currX - 1] == stackWord[0] && !visited[currY][currX - 1]){
        char toErase = stackWord[0];
        stackWord.erase(stackWord.begin());
        visited[currY][currX] = true;
        bool result = recurseSearch(index, stackWord, field, visited, indexes, currX - 1, currY);
        if(result){
            indexes[currY][currX] = index;
            field[currY][currX] = '.';
            return true;
        }
        else{
            stackWord.insert(stackWord.begin(), toErase);
            visited[currY][currX] = false;
        }
    }
    if(currX < 7 && field[currY][currX + 1] == stackWord[0] && !visited[currY][currX + 1]){
        char toErase = stackWord[0];
        stackWord.erase(stackWord.begin());
        visited[currY][currX] = true;
        bool result = recurseSearch(index, stackWord, field, visited, indexes, currX + 1, currY);
        if(result){
            indexes[currY][currX] = index;
            field[currY][currX] = '.';
            return true;
        }
        else{
            stackWord.insert(stackWord.begin(), toErase);
            visited[currY][currX] = false;
        }
    }

    return false;
}

int main(){
    char** field = new char*[8];
    int** indexes = new int*[8];
    bool** visited = new bool*[8];
    for (int i = 0; i < 8; i++){
        field[i] = new char[8];
        visited[i] = new bool[8];
        indexes[i] = new int[8];
        string row;
        cin >> row;

        for (int j = 0; j < 8; j++){
            field[i][j] = row[j];
            visited[i][j] = false;
            indexes[i][j] = -1;
        }
    }

    int m;
    cin >> m;
    string* array = new string[m];
    for (int i = 0; i < m; i++){
        cin >> array[i];
    }

    for (int _ = 0; _ < m; _++){
        string currWord = array[_];

        bool found = false;
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if(field[i][j] == currWord[0]){
                    string stackWord = currWord.substr(1, currWord.length() - 1);
                    bool result = recurseSearch(_ + 1, stackWord, field, visited, indexes, j, i);
                    if(result){
                        found = true;
                        break;
                    }
                }
            }
            if(found)
                break;
        }
    }

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << indexes[i][j] << " ";
        }
        cout << "\n";
    }
}