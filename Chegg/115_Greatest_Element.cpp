#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Size of array
    int n;
    cin >> n;
    int arr[n];
    // Input of array of elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // make new Array to store the next greatest element
    // at ith index
    int newArr[n];
    int num = -1;
    // start from last index
    // and store the maximum elemenet at each index
    for (int i = n - 1; i >= 0; i--)
    {
        num = max(num, arr[i]);
        newArr[i] = num;
    }
    // Declare and Initialize all values with zeros
    int maximumValueOfAddition = 0;
    int maximumValueOfSubstraction = 0;
    int maximumValueOfMultiplication = 0;
    int maximumValueOfDivision = 0;
    // Start from 0 to last
    for (int i = 0; i < n; i++)
    {
        // Find the maximum value of addition
        maximumValueOfAddition = max(maximumValueOfAddition, newArr[i] + arr[i]);
        // find the maximum value of substraction
        maximumValueOfSubstraction = max(maximumValueOfSubstraction, newArr[i] - arr[i]);
        // Find the maximum value of multiplication
        maximumValueOfMultiplication = max(maximumValueOfMultiplication, newArr[i] * arr[i]);
        // Find the maximum value of divison
        maximumValueOfDivision = max(maximumValueOfDivision, newArr[i] / arr[i]);
    }
    // print all values
    cout << "Maximum Addition: " << maximumValueOfAddition << endl;
    cout << "Maximum Substraction: " << maximumValueOfSubstraction << endl;
    cout << "Maximum Multiplication: " << maximumValueOfMultiplication << endl;
    cout << "Maximum Division: " << maximumValueOfDivision << endl;
    return 0;
}