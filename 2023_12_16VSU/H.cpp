#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Item {
    public:
        int index;
        int amount;
        char letter;
};

class ItemCompare {
    public:
        bool operator()(Item i1, Item i2) const {
            if(i1.amount > i2.amount){
                return true;
            }
            else if(i1.amount < i2.amount){
                return false;
            }
            return i1.index < i2.index;
        }
};

bool compareIndexes(Item i1, Item i2){
    return i1.index < i2.index;
}

int main(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    set<Item, ItemCompare> items;
    char currChar = s[0];
    int startIndex = 0;
    int currLen = 1;
    for (int i = 1; i < s.length(); i++){
        if(currChar != s[i]){
            Item item {startIndex, currLen, currChar};
            items.insert(item);

            currLen = 1;            
            currChar = s[i];
            startIndex = i;
        }
        else{
            currLen++;
        }
    }
    Item item {startIndex, currLen, currChar};
    items.insert(item);

    for (int i = 0; i < k; i++){
        Item itemToChange = *items.begin();
        items.erase(itemToChange);
        itemToChange.amount--;
        if(itemToChange.amount > 0)
            items.insert(itemToChange);
    }

    Item* array = new Item[items.size()];
    int currIndex = 0;
    for (set<Item, ItemCompare>::iterator it = items.begin(); it != items.end(); it++){
        array[currIndex++] = *it;
    }

    sort(array, array + items.size(), compareIndexes);

    for (int i = 0; i < items.size(); i++){
        Item item = array[i];
        for (int j = 0; j < item.amount; j++){
            cout << item.letter;
        }
    }
}