#include <iostream>
using namespace std;

// Shape class
class Shape
{
    // represent radius
    double radius;
    // represent side of square
    int side;
    // Represent side of length and breadth
    int length;
    int breadth;
    // Constructor to set readius of circle
    Shape(double r)
    {
        this->radius = r;
    }
    // Constructor to set side of square
    Shape(int side)
    {
        this->side = side;
    }
    // Constructor to set the length and breadth of rectangle
    Shape(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

public:
    // Return area of Circle
    double Circle()
    {
        return 3.14 * radius * radius;
    }
    // Return area of Square
    int Square()
    {
        return side * side;
    }
    // Return are of rectangle
    int Rectangle()
    {
        return length * breadth;
    }
};
