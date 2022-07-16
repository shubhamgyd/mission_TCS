#include <iostream>
using namespace std;
#include "rectangle.hpp"
void Rectangle::Width(double w)
{
    if (w > 0)
    {
        cout << "Set" << endl;
        width_ = w;
    }
    else
    {
        throw std::invalid_argument("Invalid width input");
    }
}

void Rectangle::Height(double h)
{
    if (h > 0)
    {
        height_ = h;
    }
    else
    {
        throw std::invalid_argument("Invalid height input");
    }
}

double Rectangle::returnWidth()  { return width_; };
double Rectangle::returnHeight()  { return height_; };
double Rectangle::Area() 
{
    double area = 0;
    if (width_ > 0 && height_ > 0)
    {
        area = Rectangle::returnWidth() * Rectangle::returnHeight();
    }
    return area;
}