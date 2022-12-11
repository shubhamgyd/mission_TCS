#include <stdio.h>
#include <limits.h>
void main()
{
    // Integer array of size 10
    int arr[10];
    int minNum = INT_MAX;
    // User input of 10 numbers
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        // updateMinimum Number
        if (arr[i] < minNum)
        {
            minNum = arr[i];
        }
    }
    // Print minimum number
    printf("%d", minNum);
}