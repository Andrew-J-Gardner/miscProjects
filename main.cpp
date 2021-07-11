//Andrew Gardner's Automation file!
//Things to automate:
//  1 - Grocery store trips
//  2 - chore task lists
//  3 - weekend time management schedule

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class groceryItem {
private:
    string name;
    int aisleLocated;
    bool isPerishable;
public:
    groceryItem(string p_name = "NuLL", int p_aisleLocated = -1, bool p_isPerishable = false){
        this->name = p_name;
        this->aisleLocated = p_aisleLocated;
        this->isPerishable = p_isPerishable;
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
        //listOfItems.resize(1);
    }
    int getListLength(){    return this->listOfItems.size(); }
    void addItemToList(groceryItem p_item){
        if(p_item.getName() != " "){
            this->listOfItems.push_back(p_item);
        }
        else cout << "Error in adding item: item has no name!" <<endl;
    }
    
    void removeItemFromList(int p_itemIndex){
        if(this->listOfItems.size() > p_itemIndex){
            this->listOfItems.erase(listOfItems.begin() + (p_itemIndex-1));
        } else { cout << "No such item exists!" << endl; }
    }
    void removeItemFromList(groceryItem p_item){
        int searchInd = findItemInList(p_item);
        removeItemFromList(searchInd);
    }

    //If an element with the string name provided exists in the listOfItems, finds it.
    int findItemInList(string p_searchStr){
        string searchStr = p_searchStr;
        for(int i=0; i<this->listOfItems.size(); i++){
            if(this->listOfItems.at(i).getName() == searchStr){
                cout << "Item with name " << searchStr << " found at index (" << i << ")" << endl;
                return i;
            }
        }
        cout << "Item with name " << searchStr << " NOT found" << endl;
        return -1;
    }
    //If an element with the string name from the item provided exists in the listOfItems, finds it.
    int findItemInList(groceryItem p_item){
        return findItemInList(p_item.getName());
    }

    groceryItem getItemAt(int p_index){
        return this->listOfItems.at(p_index);
    }
    void generatePath(){


    }




};


int main(){
    //placeholder
    groceryPath myPath;
    groceryItem bread("bread", 3, false);
    cout <<"first items name is: " << bread.getName() << endl;
    myPath.addItemToList(bread);
    cout <<"name of first item is: " << myPath.getItemAt(0).getName() <<endl;
    cout <<"length of list: " << myPath.getListLength() <<endl;
}