#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

struct Photo {
    string place;
    string day;
    string month;
    string hour;
    string minute;
    long long offset;
};

bool comparePhotos(pair<int, Photo> pair1, pair<int, Photo> pair2){
    Photo p1 = pair1.second;
    Photo p2 = pair2.second;
    if(p1.place < p2.place){
        return true;
    }
    else if(p1.place > p2.place){
        return false;
    }

    //place equals - compare offsets
    if(p1.offset < p2.offset){
        return true;
    }
    else if(p1.offset > p2.offset){
        return false;
    }

    //offsets equal - compare indexes
    return pair1.first <= pair2.first;
}

int main(){
    list<string> data;
    for (int i = 0; i < 100000; i++){
        string s;
        getline(cin, s);
        if(s == ""){
            break;
        }
        data.push_back(s);
    }

    pair<int, Photo>* array = new pair<int, Photo>[data.size()];
    int i = 0;
    for (list<string>::iterator it = data.begin(); it != data.end(); it++){
        string s = (*it);
        long long offset = 0;
        string place = s.substr(0, s.length() - 12);
        string day = s.substr(s.length() - 11, 2);
        string month = s.substr(s.length() - 8, 2);
        string hour = s.substr(s.length() - 5, 2);
        string minute = s.substr(s.length() - 2, 2);

        long long temp;
        stringstream(month) >> temp;
        offset += temp * 2678400;
        stringstream(day) >> temp;
        offset += temp * 86400;
        stringstream(hour) >> temp;
        offset += temp * 3600;
        stringstream(minute) >> temp;
        offset += temp * 60;

        pair<int, Photo> p {i, {place, day, month, hour, minute, offset}};
        array[i++] = p;
    }

    sort(array, array + data.size(), comparePhotos);

    for (int i = 0; i < data.size(); i++){
        pair<int, Photo> p = array[i];
        Photo ph = p.second;

        cout << (p.first + 1) << " " << ph.place << " " << 
                ph.day << "." << ph.month << ".2113 " << 
                ph.hour << ":" << ph.minute << "\n";
    }
}