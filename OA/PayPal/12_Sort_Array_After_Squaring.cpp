/*
Given an array of both positive and negative integers ‘arr[]’ which are sorted.
The task is to sort the square of the numbers of the Array.
*/

// Method 1: using squaring + sorting
// C++ program to Sort square of the numbers
// of the array
#include <bits/stdc++.h>
using namespace std;

// Function to sort an square array
void sortSquares(int arr[], int n)
{
    // First convert each array elements
    // into its square
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] * arr[i];

    // Sort an array using "sort STL function "
    sort(arr, arr + n);
}

// Driver program to test above function
int main()
{
    int arr[] = {-6, -3, -1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    sortSquares(arr, n);

    cout << "\nAfter Sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

// Time complexity: O(n log n)

// Method 2: Merge Sort
// C++ program to Sort square of the numbers of the array
#include <bits/stdc++.h>
using namespace std;

// function to sort array after doing squares of elements
void sortSquares(int arr[], int n)
{
    // first divide array into negative and positive part
    int K = 0;
    for (K = 0; K < n; K++)
        if (arr[K] >= 0)
            break;

    // Now do the same process that we learnt
    // in merge sort to merge two sorted array
    // here both two half are sorted and we traverse
    // first half in reverse manner because
    // first half contains negative elements
    int i = K - 1; // Initial index of first half
    int j = K;     // Initial index of second half
    int ind = 0;   // Initial index of temp array

    // store sorted array
    int temp[n];
    while (i >= 0 && j < n)
    {
        if (arr[i] * arr[i] < arr[j] * arr[j])
        {
            temp[ind] = arr[i] * arr[i];
            i--;
        }
        else
        {
            temp[ind] = arr[j] * arr[j];
            j++;
        }
        ind++;
    }

    /* Copy the remaining elements of first half */
    while (i >= 0)
    {
        temp[ind] = arr[i] * arr[i];
        i--;
        ind++;
    }

    /* Copy the remaining elements of second half */
    while (j < n)
    {
        temp[ind] = arr[j] * arr[j];
        j++;
        ind++;
    }

    // copy 'temp' array into original array
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

// Driver program to test above function
int main()
{
    int arr[] = {-6, -3, -1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    sortSquares(arr, n);

    cout << "\nAfter Sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

// Time complexity: O(n)
// space complexity: O(n)

// Method 3: Using two pointer

// CPP code for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to sort an square array
void sortSquares(vector<int> &arr, int n)
{
    int left = 0, right = n - 1;
    int result[n];

    // Iterate from n - 1 to 0
    for (int index = n - 1; index >= 0; index--)
    {

        // Check if abs(arr[left]) is greater
        // than arr[right]
        if (abs(arr[left]) > arr[right])
        {
            result[index] = arr[left] * arr[left];
            left++;
        }
        else
        {
            result[index] = arr[right] * arr[right];
            right--;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}

// Driver Code
int main()
{
    vector<int> arr;
    arr.push_back(-6);
    arr.push_back(-3);
    arr.push_back(-1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(5);

    int n = 6;

    cout << "Before sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    sortSquares(arr, n);
    cout << endl;
    cout << "After Sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

// Time complexity: O(n)
// Auxiliary Space: O(n)
