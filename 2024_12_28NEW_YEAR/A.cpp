#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkH(vector<vector<char>>& field, int i, int js, int je, char type){
    int count = 0;
    for (int j = 0; j < 3; j++){
        if (field[i][j] == type)
            count++;
        else if (field[i][j] != '.')
            count--;
    }
    if (count == 2){
        for (int j = 0; j < 3; j++){
            if(field[i][j] == '.'){
                cout << "0 " << i + 1 << ' ' << j + 1 << "\n" << flush;
                field[i][j] = '0';
                break;
            }
        }
        return true;
    }
    return false;
}

bool checkV(vector<vector<char>>& field, int is, int ie, int j, char type){
    int count = 0;
    for (int i = 0; i < 3; i++){
        if (field[i][j] == type)
            count++;
        else if (field[i][j] != '.')
            count--;
    }
    if (count == 2){
        for (int i = 0; i < 3; i++){
            if(field[i][j] == '.'){
                cout << "0 " << i + 1 << ' ' << j + 1 << "\n" << flush;
                field[i][j] = '0';
                break;
            }
        }
        return true;
    }
    return false;
}

bool checkDiagLeft(vector<vector<char>>& field, char type){
    int count = 0;
    for (int i = 0; i < 3; i++){
        if (field[i][i] == type)
            count++;
        else if (field[i][i] != '.')
            count--;
    }
    if (count == 2){
        for (int i = 0; i < 3; i++){
            if(field[i][i] == '.'){
                cout << "0 " << i + 1 << ' ' << i + 1 << "\n" << flush;
                field[i][i] = '0';
                break;
            }
        }
        return true;
    }
    return false;
}

bool checkDiagRight(vector<vector<char>>& field, char type){
    int count = 0;
    for (int i = 2; i >= 0; i--){
        if (field[i][i] == type)
            count++;
        else if (field[i][i] != '.')
            count--;
    }
    if (count == 2){
        for (int i = 2; i >= 0; i--){
            if(field[i][i] == '.'){
                cout << "0 " << i + 1 << ' ' << i + 1 << "\n" << flush;
                field[i][i] = '0';
                break;
            }
        }
        return true;
    }
    return false;
}

int main() {
    vector<char> hod {'X', '0', '#'};
    vector<vector<char>> field {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };

    for (int _ = 0; _ < 9; _++){
        if (hod[_ % 3] != '0'){
            //another
            char type;
            int i, j;
            if ((_ % 3) == 2){
                string status;
                cin >> status;
            }
            cin >> type >> i >> j;
            i--; j--;
            field[i][j] = type;            
        }
        else{
            if (checkH(field, 0, 0, 2, 'X'))
                continue;
            if (checkH(field, 0, 0, 2, '#'))
                continue;
            if (checkH(field, 1, 0, 2, 'X'))
                continue;
            if (checkH(field, 1, 0, 2, '#'))
                continue;
            if (checkH(field, 2, 0, 2, 'X'))
                continue;
            if (checkH(field, 2, 0, 2, '#'))
                continue;
            if (checkV(field, 0, 2, 0, 'X'))
                continue;
            if (checkV(field, 0, 2, 0, '#'))
                continue;
            if (checkV(field, 0, 2, 1, 'X'))
                continue;
            if (checkV(field, 0, 2, 1, '#'))
                continue;
            if (checkV(field, 0, 2, 2, 'X'))
                continue;
            if (checkV(field, 0, 2, 2, '#'))
                continue;
            if (checkDiagLeft(field, 'X'))
                continue;
            if (checkDiagLeft(field, '#'))
                continue;
            if (checkDiagRight(field, 'X'))
                continue;
            if (checkDiagRight(field, '#'))
                continue;
            
            bool picked = false;
            //pick random
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if (field[i][j] == '.'){
                        cout << "0 " << i + 1 << ' ' << j + 1 << "\n" << flush;
                        field[i][j] = '0';
                        picked = true;
                        break;
                    }
                }
                if (picked)
                    break;
            }
            if (picked)
                continue;;
        }
    }

    return 0;
}