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
    // 1. Set pointer at index 0 i.e. j=0 and mid =0
    // 2. if zero encounter at middle position then swap it with the lower index , increment mid and low
    // 3. if 2 occurs at the middle position then swap it with the high index and decrement high

    // solution
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        // if zero occurs at middle position
        if (arr[mid] == 0)
        {
            // swap lower and mid
            swap(arr[mid], arr[low]);
            // increment the low and mid
            low++;
            mid++;
        }
        // if 1 is at middle then continue
        else if (arr[mid] == 1)
        {
            mid++;
        }
        // if two occurs at the middle at middle
        else if (arr[mid] == 2)
        {
            // swap with the high and mid
            swap(arr[high], arr[mid]);
            // decrement high
            high--;
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