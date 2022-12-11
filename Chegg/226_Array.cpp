#include <iostream>
#include <set>
using namespace std;

void display_common(int arr1[], int arr2[])
{
    // Set to store array1 elemtns
    set<int> commonElements;
    // Push all array1 elements into the set
    for (int i = 0; i < 10; i++)
    {
        commonElements.insert(arr1[i]);
    }
    // Iterate array2 and check this number is present in set of elements or not
    // if yes then print it else ignore it
    cout << "\nCommon Elements: ";
    for (int i = 0; i < 10; i++)
    {
        if (commonElements.find(arr2[i]) != commonElements.end())
        {
            cout << arr2[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    // Array 1 and 2 declaration
    int arr1[10];
    int arr2[10];
    // Generate 10 random numbers between 20 to 50 and assign them in array1
    for (int i = 0; i < 10; i++)
    {
        // generate random number
        int randomNumber = 20 + (std::rand() % (50 - 20 + 1));
        arr1[i] = randomNumber;
    }
    // Generate 10 random numbers between 20 to 50 and assign them in array2
    for (int i = 0; i < 10; i++)
    {
        // generate random number
        int randomNumber = 20 + (std::rand() % (50 - 20 + 1));
        arr2[i] = randomNumber;
    }
    // Display Array1 Elements
    cout << "\nArray1 Elemetns: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
    // Display Array2 Elements
    cout << "\nArray2 Elements: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    // Display Common Elemetns
    display_common(arr1, arr2);
    return 0;
}