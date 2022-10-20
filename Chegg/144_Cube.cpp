#include <iostream>
using namespace std;

int main()
{
    // variable to store length,width,height
    double length, width, height;
    // Input of length width height
    cin >> length >> width >> height;

    // Find cube Inches
    double cubeInches = length * width * height;

    // Display Cube Inches
    cout << "Cube Inches: " << cubeInches << endl;

    // find cube Feet
    double cubeFeet = cubeInches / (1728 * 1.0);
    // Display Cube Feet
    cout << "Cube Feet: " << cubeFeet << endl;
    return 0;
}