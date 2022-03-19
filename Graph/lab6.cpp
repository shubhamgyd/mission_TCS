#include <iostream>
#include <string>
#include <vector>
#include "Supplies.h"
using namespace std;

//COMPLETE THIS FUNCTION
void fillVector(vector<Supplies> &supplyList){

// ask for amount of school supply items
cout << "How many school supply iteams do you want to add to the list?";
cin >> supplyList;
  
for (int i = 0; i < supplyList.size(); i++){
cout << "Enter name of school supply item #" << i + 1 << ":";
getline (cin, m_item);
  
cout << "Enter price of school supply item #" << i + 1 << ":";
cin >> m_price;
  
cout << "Enter quantity of school supply item #" << i + 1 << ":";
cin >> m_quantity;
  
}
// ask for name, price, quantity of each item and   
// add them to vector
myVector.insert (item,price,quantity);
}

//COMPLETE THIS FUNCTION
void printVectorWithoutIterator(vector<Supplies> &supplyList){

// print each item's name, price, and quantity with correct   
// precision for price
// DON'T USE ITERATOR   

}

//COMPLETE THIS FUNCTION
void printVectorWithIterator(vector<Supplies> &supplyList){

// print each item's name, price, and quantity with correct   
// precision for price
// USE ITERATOR   

}

void checkStatus(vector<Supplies> &supplyList){

//DEFINE ENUM HERE BASED ON NAMES BELOW
int listSize = supplyList.size();

switch (listSize) {
case nonMem: cout << "You did not purchase enough items to become a member." << endl;
break;
case bronze: cout << "You purchased enough items to become a bronze member." << endl;
break;
case silver: cout << "You purchased enough items to become a silver member." << endl;
break;
default: cout << "You purchased enough items to become a gold member!" << endl;
}
}

int main(){

vector<Supplies> supplyList; //Creates a new vector of school supplies

fillVector(supplyList); //Populates the vector of school supplies
printVectorWithoutIterator(supplyList); //Displays the contents of the vector
cout << endl;
printVectorWithIterator(supplyList); //Alterate way to display the contents of the vector
checkStatus(supplyList); //calls function defined above (must define enum)

return 0;
}