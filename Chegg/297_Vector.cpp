#include <iostream>
#include <vector>
using namespace std;

// Cumulative function to update the array
void cumulative(vector<int> &arr)
{
    // Iterate array and update the array
    for (int i = 1; i < arr.size(); i++)
    {
        // update the ith element
        // by adding current and previous sum
        arr[i] = arr[i - 1] + arr[i];
    }
}

int main()
{
    // Given arrays
    vector<int> arr1 = {10, 20, 10, 5};
    vector<int> arr2 = {8, 2, 9, 7, -1, 55};
    vector<int> arr3 = {0, 16, 9, 1, 64, 25, 25, 14, 0};
    // Update array1
    cumulative(arr1);
    // Update array2
    cumulative(arr2);
    // Update array3
    cumulative(arr3);
    // Print array 1 after modification
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    // Print array 2 after modification
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    // Print array 3 after modification
    for (int i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}