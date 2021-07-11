//Andrew Gardner's Automation file!
//Things to automate:
//  1 - Grocery store trips
//  2 - chore task lists
//  3 - weekend time management schedule

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class groceryItem {
private:
    string name;
    int aisleLocated;
    bool isPerishable;
public:
    groceryItem(string p_name, int p_aisleLocated, bool p_isPerishable = false){
        name = p_name;
        aisleLocated = p_aisleLocated;
        isPerishable = p_isPerishable;
    }
    string getName() {   return name;    }
    int getAisle() {   return aisleLocated;    }
    bool getPerishable() {   return isPerishable;    }
};

class groceryPath{
private:
    vector<groceryItem> listOfItems;
    const int TRAVEL_TIME_BTWN_ISLES = 3;
public:
    groceryPath(){

    }
    void addItemToList(groceryItem p_item){
        if(p_item.getName != NULL){
            this.listOfItems.push_back(p_item);
        }
        else cout << "Error in adding item: item has no name!"
    }
    void removeItemFromList(groceryItem p_item){
        if(listOfItems.findItemInList(p_item.getName()))
    }
    //If an element with the string name provided exists in the listOfItems, finds it.
    int findItemInList(string p_searchStr){
        string searchStr = p_searchStr;
        for(int i=0; i<listOfItems.length; i++){
            if(listOfItems.at(i).getName() == searchStr){
                cout << "Item with name " << seachStr << " found at index (" << i << ")" << endl;
                return i;
            }
        }
        cout << "Item with name " << seachStr << " NOT found" << endl;
        return -1;
    }
    //If an element with the string name from the item provided exists in the listOfItems, finds it.
    int findItemInList(groceryItem p_item){
        return findItemInList(p_item.getName());
    }

    void removeItemFromList(int p_itemIndex){
        if(listOfItems.at(p_itemIndex) != NULL){
            listOfItems.erase(p_itemIndex);
        } else { cout << "No such item exists!" }
    }

    void generatePath(){


    }




};


int main(){
    groceryPath myPath;
    groceryItem bread("bread", 3);
    myPath.addItemToList(bread);
}