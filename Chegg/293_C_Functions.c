// #include <stdio.h>
// // Function which calculates the average of given array of numbers
// int calcAverage(int *arr, int n)
// {
//     // get the average
//     float avg = 0.0;
//     // get the sum
//     int sum = 0;
//     // get sum by iterating array
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     // calculate average
//     avg = (sum / n);
//     // return average
//     return avg;
// }

// int main()
// {
//     // Define array
//     int arr[3] = {19, 94, 72};
//     // get size of array
//     int n = sizeof(arr) / sizeof(arr[0]);
//     // get average
//     int average = calcAverage(arr, n);
//     // print average of array
//     printf("Average: %d", average);
//     return 0;
// }

#include <stdio.h>
#include <limits.h>
int main()
{
    // Given array
    int arr[3] = {19, 94, 72};
    // Get size
    int n = sizeof(arr) / sizeof(arr[0]);
    // Initialize min and max
    int mn = INT_MAX;
    int mx = INT_MIN;
    // Iterate array and find the min and max in a given array
    for (int i = 0; i < n; i++)
    {
        // if ith element is smaller than min
        if (arr[i] < mn)
        {
            mn = arr[i];
        }
        // if ith element is greater than max
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    // print max and min
    printf("MAX: %d\n", mx);
    printf("MIN: %d", mn);
    return 0;
}