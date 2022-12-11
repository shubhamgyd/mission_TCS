#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Array before processing
    cout << "Array before processing: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Algorithm:

    // sortin all 0's before 1's
    // Steps:
    // 1. Set pointer at index 0 i.e. j=0
    // 2. If zero encounter at the ith index, then swap ith and jth element, increment the jth position
    // to the next index so we get sorted 1-bit array eleement
    // 3. Continue traversing and do swapping if zero occurs at any position

    // solution
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        // if zero found at ith index
        // do swap ith and jth elements
        if (arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            // increment j to next position
            j++;
        }
    }
    // Array after processing
    cout << "Array after processing: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
Time Complexity:O(n)
    Uses two pointer approach i.e single loop just for swapping elements, Hence required O(n) time.


Space Complexity:O(1)
    Don't used any extra storage container, Hence O(1) Space
*/