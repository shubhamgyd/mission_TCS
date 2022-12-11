#include <iostream>
using namespace std;
int main()
{
    int value, last; // value is some positive number n
    int total = 0;   // total holds the sum of the first n positive numbers
    int number;      // the amount of numbers
    float mean;      // the average of the first n positive numbers
    cout << "Please enter a positive integer" << endl;
    cin >> value;
    cout << "Please enter the ending positive integer" << endl;
    cin >> last;
    // If value is valid
    if (value > 0)
    {
        // Iterate from the value to the last number
        for (number = value; number <= last; number++)
        {
            // add number into the total
            total = total + number;
        }
        // Find the mean using total sum / total numbers from first to the last
        mean = ((float)total / ((float)last - (float)value + (float)1));
        // Display mean average
        cout << "The mean average of from " << value << " to " << last << " is " << mean << endl;
    }
    // Else display error
    else
    {
        cout << "Invalid input - integer must be positive" << endl;
    }
    return 0;
}