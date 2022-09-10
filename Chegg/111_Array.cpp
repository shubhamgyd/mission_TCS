#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

// Function which initialze array with whole numbers
void initializeArray(int arr[], int size)
{
    // Initialize array with whole number
    // from 0 to size-1
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
}

// Display array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// createNew Array by random shuffeling elements from old array
//  and then assign into new array
void createNewArray(int arr[], int newArray[], int size)
{
    // To obtain a time-based seed
    unsigned seed = 0;

    // Use of shuffle
    shuffle(arr, arr + size, default_random_engine(seed));

    // now assign this shuffled elemtns to new Array
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
    }
}

int main()
{
    cout << "Enter size of array: ";
    // size of array
    int size;
    cin >> size;
    // create newArray
    int arr[size];
    // function call which iniitalize with whole
    // numbers
    initializeArray(arr, size);
    cout << "Old Array: ";
    // Display old array
    displayArray(arr, size);
    // make newArray
    int newArray[size];
    // function which createNew array
    createNewArray(arr, newArray, size);
    cout << "New Shuffled Array: ";
    // display new Shuffled array
    displayArray(newArray, size);
}