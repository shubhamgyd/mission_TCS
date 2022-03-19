#include <iostream>
#include <string>
#include "Supplies.h"
using namespace std;

//Default Constructor for Classes   
Supplies::Supplies(){
m_item = "notebook";
m_price = 2.45;
m_quantity = 3;
}

//Overloaded Constructor for Classes
Supplies::Supplies(string item, double price, int quantity){
m_item = item;
m_price = price;
m_quantity = quantity;
}

//Name: setItem   
//Sets what the item is   
void Supplies::setItem(string item){
m_item = item;
}

//Name setPrice   
//Sets the price of object
void Supplies::setPrice(double price){
m_price = price;
}

//Name: setQuantity   
//Sets the quantity of the item to be purchased   
void Supplies::setQuantity(int quantity){
m_quantity = quantity;
}

//Name: getItem   
//Returns the name of the item
string Supplies::getItem(){
return m_item;
}

//Name: getPrice
//Returns the price of the item   
double Supplies::getPrice(){
return m_price;
}

//Name: getQuantity   
//Returns the quantity of the item
int Supplies::getQuantity(){
return m_quantity;
}