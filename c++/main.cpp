//Andrew Gardner's Automation file!
//Things to automate:
//  1 - Grocery store trips
//  2 - chore task lists
//  3 - weekend time management schedule

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

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
    vector<string> linearPath;
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
        groceryItem tempItem = this->listOfItems.at(p_itemIndex);
        if(this->listOfItems.size() > p_itemIndex){
            this->listOfItems.erase(listOfItems.begin() + (p_itemIndex-1));
            cout <<endl<< "Item " <<tempItem.getName()<< " removed!";
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
    int findLargestAisle(){
        int highestAisle = 1;
        int aisleInd = -1;
        for(int i=0; i<this->listOfItems.size(); i++){
            aisleInd = this->listOfItems.at(i).getAisle();
            if(highestAisle < aisleInd) {
                highestAisle = aisleInd;
            }

        }
        cout <<endl<< "Highest aisle in listOfItems is: "<<highestAisle;
        return highestAisle;
    }
    //Generates a grocery list sorted by aisles
    void generateLinearPath(){
        int lastAisle = this->findLargestAisle();
        vector<std::string> genList = {" "}; 
        genList.pop_back(); //Makes the list empty, ready for use
        
        
        string tempStr = " ";
        int LOILength = this->listOfItems.size();
        int aisleIter = 1;
        //Sorts groceryItems by aisle
        while(genList.size() < this->listOfItems.size()){
            if(aisleIter > lastAisle) { aisleIter = 0; break; }    //if the aisleIterator is larger than the largest aisle in the list, breaks method since something went wrong
            for(int i=0; i<LOILength; i++){
                tempStr = this->listOfItems.at(i).getName();
                if(this->listOfItems.at(i).getAisle() == aisleIter){
                    if(tempStr != "NuLL"){
                        genList.push_back(tempStr);
                    }
                }
            }
            aisleIter++;
        }
        //Debug For loop
        for(int i=0; i<genList.size(); i++){
            cout <<endl<<genList.at(i);
        }
        this->linearPath = genList;
    }

    void printList(){
        string printStr = " ";
        for(int i=0; i < this->listOfItems.size(); i++){
            printStr = this->listOfItems.at(i).getName();
            cout << endl <<"(" << i << "): " << printStr;
        }
        cout << endl;
    }
    void printGenList(){
        string printStr = " ";
        for(int i=0; i < this->linearPath.size(); i++){
            printStr = this->linearPath.at(i);
            cout << endl <<"(" << i << "): " << printStr;
        }
        cout << endl;
    }


};


int main(){
    groceryPath myPath;
    groceryItem bread("bread", 3, false);
    groceryItem milk("milk", 8, false);
    groceryItem cereal("cereal", 5, false);
    groceryItem potatoes("potatoes", 7, false);
    groceryItem carrots("carrots", 2, false);
    groceryItem chocolate("chocolate", 15, false);

    myPath.addItemToList(bread);
    myPath.addItemToList(milk);
    myPath.addItemToList(cereal);
    myPath.addItemToList(potatoes);
    myPath.addItemToList(carrots);
    myPath.addItemToList(chocolate);
    myPath.generateLinearPath();
    myPath.printList();
    myPath.removeItemFromList(3);
    myPath.printList();
    //myPath.printGenList();

    myPath.findLargestAisle();
}