#include <iostream>
using namespace std;

// Class
class Circle
{
    // radius of circle
    double radius;

public:
    // Constructor to set the radius
    Circle(double r)
    {
        radius = r;
    }
    // function which returns the area of a circle
    double area()
    {
        // fornula of area of circle
        return 3.142 * radius * radius;
    }
    double perimeter()
    {
        // formula of perimeter of circle
        return 2 * 3.142 * radius;
    }
};

int main()
{
    double radius;
    cout << "Enter radius: ";
    cin >> radius;
    // Creating object and calling constructor
    Circle obj(radius);
    // print area
    cout << "Area of circle: " << obj.area() << endl;
    // print perimeter
    cout << "Perimeter of circle: " << obj.perimeter() << endl;
    return 0;
}