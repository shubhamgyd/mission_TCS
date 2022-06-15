#include<iostream>
using namespace std;


// Rectangle Class
class Rectangle
{
    // data members
    double width;
    double length;
public:
    // Default constructor
    Rectangle()
    {
        this->width=0;
        this->length=0;
    }

    // Parametarize constructor
    Rectangle(double w,double l)
    {
        // set values of wigth and length
        this->width=w;
        this->length=l;
    }

    // calculating the area of rectangle
    double printArea()
    {
        // formula of area of rectangle
        double area=length*width;


        // return area
        return area;
    }
};

int main()
{
    // Example 1
    Rectangle rectangle1=Rectangle();
    cout<<"Area of Rectangle= "<<rectangle1.printArea()<<endl;
    cout<<endl;


    // Example 2
    Rectangle rectangle2=Rectangle(0.3,6.7);
    cout<<"Area of Rectangle= "<<rectangle2.printArea()<<endl;
}