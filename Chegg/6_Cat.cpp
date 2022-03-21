#include<bits/stdc++.h>
using namespace std;

// structure for stroing Cat information
struct Cat
{
    // filed of cat
    string name,breed;
    int age;
    double insurance=99.9;
    double ownPrice=0.0;
    void setCat(string nameCat,string orginCat,int ageCat);
    void caclculatePrice();
    void showCat();
};


// function to set the cat dat
void Cat::setCat(string nameCat,string orignCat,int ageCat)
{
    name=nameCat;
    breed=orignCat;
    age=ageCat;
}

// function to calculate the cat owing price according to formula
void Cat::caclculatePrice()
{
    ownPrice=age*1.5+insurance;
}

// function to display cat information
void Cat::showCat()
{
    cout<<"Cat: "<<name<<" is a "<<breed<<endl;
    cout<<"Its age is "<<age<<endl;
    cout<<"Insurance fee: $"<<insurance<<endl;
    cout<<"Owing cost is: $"<<ownPrice<<endl;
}

int main()
{
    Cat myCat;
    myCat.setCat("Tiger","British Shorthair",1);
    myCat.caclculatePrice();
    myCat.showCat();
}
